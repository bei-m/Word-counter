#include "library.h"

void irasymas(string &a,map<string, vector<int>> &zodziai, int line)
{
    //TIKRINIMAS
    if (a!="I"){
    std::regex reg ("^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$");
    if (regex_match(a,reg)) {a.clear();}}

    bool b=true;
    for (char &c : a) 
    {if (isascii(c)==0) {c='-';}}
    
    for (int i=a.size()-1; i>-1; i--)
    {
        if (!isalpha(a.at(i)))
        {
            if (a.at(i)=='-') {a.at(i)=' '; b=false;}
            else if (a.at(i)=='\''&&a.at(i)!=a.back()) {a = a.substr(0, i); break;}
            else {a.erase(i,1);}
        }
    }
    //IRASYMAS
    if (!b)
    {
        stringstream eilute(a);
        string word;
        while(eilute>>word)
        {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            word[0]=toupper(word[0]);
            zodziai[word].push_back(line);
        }
    }
    else
    {
        if (!a.empty())
        {
            transform(a.begin(), a.end(), a.begin(), ::tolower);
            a[0]=toupper(a[0]);
            zodziai[a].push_back(line);
        }
    }
}


int main()
{
    bool b=true;
    string pav;
    cout<<"(.txt) failai šiuo metu esantys aplanke: "<<endl;
    system("ls *.txt");
    do 
    {
    cout<<"Įrašykite norimo (.txt) failo pavadinimą: ";
    getline(cin,pav);
    pav.find(".TXT")!=pav.npos? pav.erase(pav.length()-4):pav=pav;
    pav.find(".txt")!=pav.npos? pav=pav:pav=pav+".txt";
    ifstream data(pav);
    try
    {
        const char* ff=pav.c_str();
        FILE *fp;
        fp=fopen(ff, "r");
        data.peek();
        if (fp==NULL) { throw   "Klaida. Nepavyko rasti tokio failo. ";}
        if (data.eof()) {throw  "Klaida. Failas yra tuščias. ";}
        b=true;
    }
    catch(const char* er)
    { cout<<er; b=false;} 
    }while(!b);

    ifstream data(pav);
    map<string, vector<int>> zodziai;
    set<string> nuorodos;
    string x,word;
    int line=0;
    stringstream eilute;
    while(getline(data,x))
    {
        line++;
        eilute.str(x);
        while(eilute>>word)
        {
            if (ispunct(word.back())) {word.pop_back();}
            if (word.find("www.")!=string::npos||word.find("http://")!=string::npos||word.find("https://")!=string::npos) 
            {nuorodos.insert(word);}
            else
            {irasymas(word, zodziai, line);}
        }
        eilute.clear();
    }
    data.close();
    int ilgis_l=to_string(line).size();
    int ilgis_z=0;
    auto it=zodziai.begin();
    while(it!=zodziai.end())
    {
        if (it->second.size()<2)
        {it=zodziai.erase(it);}
        else 
        {
            if (it->first.size()>ilgis_z) {ilgis_z=it->first.size();}
            it++;
        }
    }
    string skirtukas;
    ofstream rez("rezultatai.txt");
    fill_n(back_inserter(skirtukas), ((ilgis_z+40)/2), '=');
    rez<<skirtukas<<"NUORODOS("<<nuorodos.size()<<")"<<skirtukas<<endl;
    for (auto &j:nuorodos)
    {
        rez<<j<<endl;
    }
    skirtukas.clear();
    fill_n(back_inserter(skirtukas), ((ilgis_z+24)/2), '=');
    rez<<endl<<skirtukas<<"PASIKARTOJANTYS ŽODŽIAI("<<zodziai.size()<<")"<<skirtukas<<endl;
    rez<<setw(ilgis_z+3)<<left<<"Žodis "<<setw(10)<<left<<"| Kiekis"<<setw(10)<<left<<"| Eilutės"<<endl;
    skirtukas.clear();
    fill_n(back_inserter(skirtukas), (ilgis_z+50), '-');
    rez<<skirtukas<<endl;
    int q;
    string skirtukas2;
    for (auto &i: zodziai)
    {
        q=0;
        skirtukas2.clear();
        fill_n(back_inserter(skirtukas2), (ilgis_z+3+12), ' ');
        rez<<setw(ilgis_z+3)<<left<<i.first<<setw(12)<<left<<i.second.size();
        for (auto &j:i.second)
        {
            rez<<setw(ilgis_l)<<j<<" "; q++;
            if (q%12==0&&i.second.size()!=q) {rez<<endl<<skirtukas2;}
        }
        rez<<endl<<skirtukas<<endl;
    }

    cout<<"Rezultatus galite rasti 'rezultatai.txt' faile.";
    return 0;
}