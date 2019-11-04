/*Implementare una rubrica telefonica seguendo le seguenti specifiche:
0) Definire una enumerazione 'TipologiaContatto' che permetta di utilizzare i seguenti valori: lavoro, famiglia, amici, altri.
1) Definire una struttura 'Contatto' contenente:
- nome, cognome, numero di telefono, indirizzo email, tipologia contatto
2) Implementare una funzione o procedura che acquisisca i campi di un Contatto e restituisca tale contatto. Effettuare i controlli sull'input:
- nome (non vuoto, non deve contenere cifre)
- cognome (non vuoto, non deve contenere cifre)
- numero di telefono (non vuoto, non deve contenere simboli o lettere)
- indirizzo email (deve contenere almeno un carattere prima della chiocciola, almeno un carattere chiocciola, almeno un
 carattere dopo la chiocchiola, un punto e un dominio come com o it)
- tipologia (deve essere richiesto in modo semplice per l'utente, ad esempio usando un menu)
3) Implementare una procedura che stampi in modo chiaro e ordinato tutti i dati del contatto
4) Implementare una funzione o procedura che permetta la modifica di un contatto. Riceverà come parametro un contatto,
 lo stamperà e chiederà quale campo deve essere modificato. Una volta inserito il nuovo valore, a seconda dei casi il
 contatto dovrà essere restituito al chiamante o meno (dipende se si utilizza una procedura o una funzione).
5) Implementare una funzione che inizializzi un vettore dinamico. Essa dovrà allocare lo spazio per un contatto e restituire
 l'indirizzo di memoria relativo se l'allocazione è andata a buon fine. Altrimenti il programma terminerà comunicando all'utente
 tale malfunzionamento.
6) Implementare la funzione di inserimento seguendo la logica seguente: passo il contatto, aumento lo spazio del vettore dinamico
 per contenere un nuovo elemento e a questo punto inserisco il nuovo contatto seguendo l'ordine alfabetico. Si possono presentare
 due casi: inserimento in coda, inserimento non in coda. Se in coda non dovremo far altro che inserire il contatto nell'ultima (e nuova)
 posizione, altrimenti una volta trovato il contatto successivo in ordine alfabetico dovremo far scorrere tutti i contatti di una posizione
 e inserire il nuovo contatto nella corretta posizione. Al termine delle operazioni ricordarsi di tenere traccia dell'eventuale cambio
 di valore del puntatore al vettore dinamico.
7) Implementare la funzione di eliminazione offrendo le seguenti possibilità:
- eliminare tutta la rubrica
- eliminare un contatto con un certo indice
- eliminare tutti i contatti con un certo nome o cognome
- elininare una categoria di contatti
In tutti i casi dovremo sempre stare attenti a modificare lo spazio occupato dal vettore, se ad esempio abbiamo un vettore di 3 contatti
 A, B e C e dobbiamo eliminare B sposteremo C in B e riallocheremo lo spazio eliminando un elemento (l'ultimo).
 Ricordarsi sempre di restituire il puntatore al vettore dinamico.
 8) Aggiungere alle funzionalità del programma la ricerca dei contatti offrendo le seguenti possibilità:
- ricerca mediante nome (o parte del nome)
- ricerca mediante cognome (o parte del cognome)
- ricerca mediante mail (o parte del mail)
- ricerca mediante numero
- ricerca mediante categoria*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30
#define DIM_NOME 20
#define DIM_COGNOME 30
#define DIM_TELEFONO 10
#define DIM_EMAIL 30
#define N_NOMI 7
#define N_COGNOMI 7
#define N_TELEFONI 7
#define N_EMAIL 7
#define N_TIPOLOGIE 4

typedef enum {LAVORO, FAMIGLIA, AMICI, ALTRI} TipologiaContatto;
typedef struct {
    char nome [DIM+1];
    char cognome [DIM+1];
    char numeroDiTelefono [DIM+1];
    char email [DIM+1];
    TipologiaContatto tipologiaContatto;
} Contatto; //Creazione della struttura "Contatto" (Punto 1)

Contatto generaContattoRandom(); //funzione genera-contatto che ci ha passato Fabio
void acquisisciContatto (Contatto persona); //procedura che si occupa di acquisire tutti i campi di un Contatto (Punto 2)
void stampaContatto (Contatto persona); // procedura che stampa in modo ordinato tutti i campi di un contatto (Punto 3)
void modificaContatto (Contatto persona); //procedura che modifica i campi di un Contatto (Punto 4)
void modNome (Contatto persona); // procedura di modifica del nome
void modCognome (Contatto persona); // procedura di modifica del cognome
void modNumero (Contatto persona); // procedura di modifica del numero di telefono
void modEmail (Contatto persona); // procedura di modifica dell'indirizzo email
void modTipo (Contatto persona); // procedura di modifica della tipologia contato
int vettoreDinamico (Contatto persona); //inizializzazione del vettore dinamico (Punto 5)

int main() {

    Contatto persona;

    persona = generaContattoRandom();
    stampaContatto(persona);


    return 0;
}

void acquisisciContatto (Contatto persona){
    int i;

    //acquisizione del nome
    printf("\nNome:");
    scanf("%30[^\n]s", persona.nome);
    getchar();

    for (i = 0; persona.nome[i] != '\0'; i++) {
        while (persona.nome[i] >= 'a' && persona.nome[i] <= '9' || persona.nome[0] == ' '){ //il nome non deve contenere cifre e non deve essere vuoto
            printf("\nErrore, riprova:");
            scanf("%30[^\n]s", persona.nome);
            getchar();
        }
    }
    //acquisizione cognome
    printf("\nCognome:");
    scanf("%30[^\n]s", persona.cognome);
    getchar();

    for (i = 0; persona.cognome[i] != '\0'; i++) {
        while (persona.nome[i] >= '0' && persona.cognome[i] <= '9' || persona.cognome[0] == ' '){ //il cognonome non deve contenere cifre e non deve essere vuoto
            printf("\nErrore, riprova:");
            scanf("%[^\n]s", persona.cognome);
            getchar();
        }
    }

    //acquisizione numero
    printf("\nNumero:");
    scanf("%30[^\n]s", persona.numeroDiTelefono);
    getchar();

    for (i = 0; persona.numeroDiTelefono[i] != '\0'; i++) {
        while (!(persona.numeroDiTelefono[i] >= '0' && persona.numeroDiTelefono[i] <= '9')){ //il numero deve contenere solo cifre
            printf("\nErrore, riprova:");
            scanf("%[^\n]s", persona.numeroDiTelefono);
            getchar();
        }
    }

    //acquisizione email
    printf("\nEmail:");
    scanf("%30[^\n]s", persona.email);
    getchar();

    for (i = 0; persona.email[i] != '\0'; i++) {
        while (persona.email [0] == '@'){ //non si può scrivere la @ per prima. Unica condizione riuscita
            printf("\nErrore, riprova:");
            scanf("%30[^\n]s", persona.email);
            getchar();
        }
    }

    printf("\nTipo Contatto:[0=LAVORO, 1=FAMIGLIA, 2=AMICI, 3=ALTRI]");
    scanf("%d", &persona.tipologiaContatto);
    getchar();

    stampaContatto(persona);
}
void stampaContatto (Contatto persona){
    printf("\n\nNome: %s", persona.nome);
    printf("\nCognome: %s", persona.cognome);
    printf("\nNumero: %s", persona.numeroDiTelefono);
    printf("\nEmail: %s", persona.email);
    switch (persona.tipologiaContatto){
        case 0:
            printf("\nTipo: Lavoro");
            break;
        case 1:
            printf("\nTipo: Famiglia");
            break;
        case 2:
            printf("\nTipo: Amici");
            break;
        case 3:
            printf("\nTipo: Altri");
            break;
    }

}
void modificaContatto (Contatto persona){
    int scelta;

    persona = generaContattoRandom();
    stampaContatto(persona); //visualizza contatto che si vuole modificare

    printf("\nQuale campo vuoi modificare? [1=Nome, 2=Cognome, 3=Numero, 4=Email, 5=Tipologia]\nPremere qualunque altro tasto per uscire.");
    scanf("%d", &scelta); //switch con all'interno le varie sotto-procedure di modifica che si attivano in base alla scelta dell'utente

    switch (scelta) {
        case 1:
            modNome(persona);
            break;

        case 2:
            modCognome(persona);
            break;

        case 3:
            modNumero(persona);
            break;

        case 4:
            modEmail(persona);
            break;

        case 5:
            modTipo(persona);
            break;

        default:
            printf("\nNon e\' stata apportata alcuna modifica.");
    }
}
void modNome (Contatto persona){
    int i;

    printf("\nNuovo Nome:");
    scanf("%s", persona.nome);
    getchar();

    for (i = 0; persona.nome[i] != '\0'; i++) {
        while (persona.nome[i] >= '0' && persona.nome[i] <= '9' || persona.nome[0] == ' '){
            printf("\nErrore, riprova:");
            scanf("%s", persona.nome);
            getchar();
        }
    }
    printf("\nModifica eseguita con successo.");
    printf("\nNome: %s", persona.nome);
}
void modCognome (Contatto persona){
    int i;
    printf("\nNuovo Cognome:");
    scanf("%s", persona.cognome);
    getchar();

    for (i = 0; persona.cognome[i] != '\0'; i++) {
        while (persona.nome[i] >= '0' && persona.cognome[i] <= '9' || persona.cognome[0] == ' '){
            printf("\nErrore, riprova:");
            scanf("%s", persona.cognome);
            getchar();
        }
    }
    printf("\nModifica eseguita con successo.");
    printf("\nCognome: %s", persona.cognome);
}
void modNumero (Contatto persona){
    int i;
    printf("\nNuovo Numero:");
    scanf("%s", persona.numeroDiTelefono);
    getchar();

    for (i = 0; persona.numeroDiTelefono[i] != '\0'; i++) {
        while (!(persona.numeroDiTelefono[i] >= '0' && persona.numeroDiTelefono[i] <= '9')){
            printf("\nErrore, riprova:");
            scanf("%s", persona.numeroDiTelefono);
            getchar();
        }
    }
    printf("\nModifica eseguita con successo.");
    printf("\nNumero: %s", persona.numeroDiTelefono);
}
void modEmail (Contatto persona){
    int i;
    printf("\nNuova Email:");
    scanf("%s", persona.email);
    getchar();

    for (i = 0; persona.email[i] != '\0'; i++) {
        while (persona.email [0] == '@'){
            printf("\nErrore, riprova:");
            scanf("%s", persona.email);
            getchar();
        }
    }
    printf("\nModifica eseguita con successo.");
    printf("\n\nEmail: %s", persona.email);
}
void modTipo (Contatto persona){
    printf("\nNuovo Tipo Contatto:[0=LAVORO, 1=FAMIGLIA, 2=AMICI, 3=ALTRI]");
    scanf("%d", &persona.tipologiaContatto);
    getchar();
    printf("\nModifica eseguita con successo.");
    printf("\nTipo: %d", persona.tipologiaContatto);
}
int vettoreDinamico (Contatto persona){
    Contatto *a = NULL;
    int n;

    printf("\nQuanti nuovi contatti vuoi memorizzare?");
    scanf("%d", &n);

   a = (Contatto *)malloc(n * sizeof(Contatto));
    if (a == NULL) {
        printf("\nErrore: l\'allocazione non e\' andata a buon fine.");
        exit(-1);
    }else
        printf("\nL\'indirizzo di memoria e\':%p", &a);

    return a;
}
Contatto generaContattoRandom(){
    Contatto c;
    char nomi[N_NOMI][DIM_NOME+1] = {"Paolo", "Luca", "Enzo", "Fabio", "Carlo", "Maria", "Alessandra"};
    char cognomi[N_COGNOMI][DIM_COGNOME+1] = {"Viola", "Rossi", "Blu", "Marrone", "Neri", "Verdi", "Bianchi"};
    char telefoni[N_TELEFONI][DIM_TELEFONO+1] = {"3472838393", "3483783923", "3472899393", "3472656593", "3472090393", "3472987593", "3498838393"};
    char email[N_EMAIL][DIM_EMAIL+1] = {"mail@gmail.it", "mail@libero.it", "mail@tiscali.it", "mail@unica.it", "mail@yahoo.it", "mail@apple.it", "mail@gmail.it"};

    strcpy(c.nome, nomi[rand()%N_NOMI]);
    strcpy(c.cognome, cognomi[rand()%N_COGNOMI]);
    strcpy(c.numeroDiTelefono, telefoni[rand()%N_TELEFONI]);
    strcpy(c.email, email[rand()%N_EMAIL]);
    c.tipologiaContatto = rand()%N_TIPOLOGIE;

    return c;
}