EXAMEN
Programare orientată pe obiecte

Pentru a veni în sprijinul vecinilor din cartierul dumneavoastră, vă decideți să realizați o aplicație pentru curierat de produse. Aplicația proiectată are următoarele particularități:

-	fiecare vecin va avea un cont de client, care poate fi de tip obișnuit sau special:
-	ambele tipuri de clienți vor avea un nume și un buget;
-	clienții obișnuiți pot avea stocată o singură adresă de domiciliu și au un istoric cu maxim 10 comenzi;
-	clienții speciali pot stoca până la 3 adrese de domiciliu și au un istoric cu un număr nelimitat de comenzi.
  
-	fiecare tip de client poate lansa un anumit tip de comenzi:
-	comenzile simple, care pot fi lansate de către ambele tipuri de clienți, pot conține maxim 5 produse.
-	comenzile jumbo, care pot fi lansate doar de către clienții speciali, pot conține un număr nelimitat de produse.
  
-	toate comenzile vor conține denumirile și numărul de bucăți ale produselor alese de clienți din catalogul de produse existent la nivelul Curierului.
  
-	comenzile clienților vor fi preluate de entitatea unică Curier, le va aloca un ID unic, apoi le va procesa prin interogarea unei alte entități unice, Magazin, pentru aflarea disponibilității produselor și calcularea valorii comenzii. Dacă un produs nu este disponibil, acesta nu va fi inclus în calculul sumei de plată aferentă fiecărei comenzi.
  
-	Curierul va avea un catalog de produse, primit de la Magazin. Catalogul de produse va conține doar informații privind denumirea și prețul produselor din Magazin.
  
-	valoarea finală a unei comenzi va fi scăzută de Curier din bugetul pe care clientul îl are în contul său. În cazul în care bugetul clientului este insuficient, se vor elimina din comandă ultimele produse adăugate, unul câte unul, până când bugetul clientului este suficient pentru plata comenzii. Acest lucru va necesita și o actualizare a stocului de produse din Magazin.
  
-	magazinul va avea un stoc de produse, care va conține denumirea, prețul și cantitatea fiecărui produs.  În momentul în care Curierul achiziționează un produs din Magazin, stocul Magazinului va fi actualizat.
  
-	după realizarea achiziției de produse, Curierul va genera o chitanță pe care o va transfera clientului. Chitanța va conține toate produsele din comanda clientului, cu următoarele mențiuni:
  
-	produsele disponibile și achiziționate vor avea notat prețul per bucată, prețul total și mențiunea achiziționat;
-	produsele disponibile, dar neachiziționate (în cazul în care bugetul a fost insuficient), vor avea notat prețul per bucată și mențiunea buget insuficient, prețul total fiind 0;
-	produsele indisponibile vor avea notat prețul per bucată și mențiunea indisponibil, prețul total fiind 0.

Exemplu de chitanță afișată în consolă:

Chitanță pentru comanda cu ID-ul 1123:
-	Săpun lichid: 1 buc. x 12 lei = 12 lei (achiziționat)
-	Pâine: 2 buc. x 5 lei = 10 lei (achiziționat)
-	Gogoși: 3 buc. x 6 lei = 18 lei (achiziționat)
-	Tigaie: 1 buc. x 100 lei = 0 lei (indisponibil)
-	Oală presiune: 1 buc. x 400 lei = 0 lei (buget insuficient)
	Suma totală plătită: 40 lei

Fluxul de lucru:
-	un client își creează contul, afișează bugetul disponibil și apoi lansează o comandă, cu diferite produse alese din catalog, pe care o plasează curierului.
-	curierul preia comanda, interoghează magazinul privind disponibilitatea produselor, calculează suma totală de plată, actualizează bugetul din contul clientului și generează chitanța.
-	magazinul actualizează stocurilor în funcție de fiecare comandă.
-	clientul afișează chitanța primită și bugetul rămas.

Cerințe de care trebuie să țineți cont:
-	stocul de produse de la nivelul magazinului va fi încărcat dintr-un fișier/sistem de fișiere, cu un format la alegere, și va conține cel puțin 15 produse, fiecare având o cantitate și un preț. 
-	catalogul de produse va fi inițializat pe baza acestui stoc de produse și va conține produsele ordonate alfabetic (se recomandă utilizarea unei funcții lambda pentru această operațiune).
-	se va folosi conceptul de move semantics pentru transferul comenzii de la Client la Curier și a chitanței de la Curier la Client.
-	vor fi utilizate mecanisme de tratare a excepțiilor în cazul identificării unui produs indisponibil sau a depășirii bugetului aferent fiecărui client.
-	vor fi utilizate, obligatoriu, următoarele concepte: interfață, moștenire, metode virtuale, funcții friend, polimorfism;
-	folosirea mecanismului de supraîncărcare a operatorilor, pentru îndeplinirea anumitor cerințe (de ex. afișarea catalogului de produse).

Timp de lucru: 120 min.
Punctaj maxim pe subiect: 9p (1p din oficiu).
Obs: Rezolvările cu erori de compilare vor fi apreciate cu nota 2. Componentele dezvoltate pentru care nu exista secvențe de test (de ex. în programul principal) nu vor fi luate în considerare pentru notare.
