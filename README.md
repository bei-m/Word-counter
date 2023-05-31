# Žodžių skaičiuoklė (Word counter)

Programa, iš naudotojo pasirinkto (.txt) failo:
1) Išrenka ir suskaičiuoja esančias nuorodas (ieškomos nuorodos, su galūnėmis pateiktomis 'g.txt' faile).
2) Išrenka ir suskaičiuoja faile pasikartojančius žodžius.

## Programos veikimas:
1) Iš pradžių programa išvardins failų, kurie šiuo metu yra aplanke, pavadinimus ir paprašys naudotojo įrašyti norimo failo pavadinimą. <br>
2) a) Jei failas bus nerastas arba tuščias, programa paprašys naudotojo įvesti kito failo pavadinimą. <br>
   b) Jei failas bus rastas ir ne tuščias, programa išrinks ir suskaičiuos nuorodas ir pasikartojančius žodžius, o rezultatus pateiks faile 'rezultatai.txt‘ <br>
   

## Programos paleidimas:
1) Terminale įrašyti _make && ./prog_ 
2) Įvesti norimo failo pavadinimą.

## Svarbu:
* Programa skirta tik tekstams, kuriuose nėra lietuviškų raidžių (naudojant lietuvišką tekstą programa veiks, tačiau lietuviškas raides traktuos kaip simbolius ir ištrins). 
* Tekste galima naudoti romėniškus skaičius, (išskyrus 'I‘, jis traktuojamas kaip žodis).
* Įvestis priimama tik su 'enter‘ paspaudimu.
* Naudotojo norimo failo pavadinimas negali būti 'g.txt'.
* Norimas, papildomas nuorodų galūnes naudotojas gali įrašyti į 'g.txt' failą.
