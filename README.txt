1. grep
Timpul necesar pentru a inplementa programul a fost de aproximativ 6-7h(cu on eroare de 2h).
Porgramul citeste un sir ce este cautat intr-un text, citit si acesta de la tastatura. Cand il gaseste, este inlocuit cu un alt sir.
Sirul cu care se inlocuieste este generat cu formatarea sirului cautat, astfel incat sa apara colorat rosu in terminal.
La final, se afiseaza liniile care contin noul sir.
Programul foloseste trei functii.
Doua functii, una pentru alocarea memoriei matricei in care se stocheaza textul, respectiv eliberarea acesteia.
Cea de-a treia generareaza sirul coolorat.

2. cut

3. sort
Timpul necesar pentru a implementa programul a fost de aproximativ 5-6h(cu o eroare de 1h).
Programul citeste o matrice a notelor alocata dinamic.
Acesteia ii este alocat atat spatiu cat are nevoie.
Se calculeaza medie in ultimul element al fiecarei linii.
Se sorteaza apoi liniile in ordine descrescatoare dupa medie(ultimul element).
In final, mediile si notele aferenete sunt afisate, fiecare pe cate o linie.
Am folosit doua functii, una pentru alocare, respectiv una pentru eliberarea memoriei in matrice.

4. encrypt
Timpul necesar pentru a implementa programul a fost de aproximativ 6-7h(cu o eroare de 1h).
Programul citeste un text pe care il codifica.
Se verifica pe fiecare linie elementele unul cate unul.
Daca acesta este la inceputul unui cuvant sau este delimitator de cuvinte(spatiu sau \n), atunci este afisat far codificare.
Cand se gaseste primul caracter dintr-un cuvant, acesta se salveaza, se afiseaza si se verifica daca cuvantul contine doar numere.
Daca se gaseste un caracter care se afla in interiorul unui cuvant, atunci se verifica daca se afla intr-un cuvant format doar din numere.
In caz afirmativ, se afiseaza fara codificare; altfel se face codificarea conform metodei date in text.
S-au folosit functii pentru alocare si eliberare a memoriei si pentru a verifica daca un cuvant este format doar din numere sau nu.