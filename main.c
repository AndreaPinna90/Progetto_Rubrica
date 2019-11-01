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

typedef enum {LAVORO, FAMIGLIA, AMICI, ALTRI} TipologiaContatto;
typedef struct {
    char nome [DIM+1];
    char cognome [DIM+1];
    char numeroDiTelefono [DIM+1];
    char email [DIM+1];
    TipologiaContatto tipologiaContatto;
} Contatto;

void acquisisciContatto (Contatto persona);//certe condizioni input da rivedere
void acquisisciNome (Contatto persona);
void acquisisciCognome (Contatto persona);
void acquisisciNumero (Contatto persona);
void acquisisciEmail (Contatto persona);
void acquisisciTipo (Contatto persona);
void stampaContatto (Contatto persona);
void modificaContatto (Contatto persona);
int vettoreDinamico (Contatto persona);

int main() {
    Contatto Andrea;

    acquisisciContatto(Andrea);

    return 0;
}

void acquisisciContatto (Contatto persona){
    int i;

    printf("\nNome:");
    scanf("%30[^\n]s", persona.nome);
    getchar();

    for (i = 0; persona.nome[i] != '\0'; i++) {
        while (persona.nome[i] >= '0' && persona.nome[i] <= '9' || persona.nome[0] == ' '){
            printf("\nErrore, riprova:");
            scanf("%30[^\n]s", persona.nome);
            getchar();
        }
    }
    printf("\nCognome:");
    scanf("%30[^\n]s", persona.cognome);
    getchar();

    for (i = 0; persona.cognome[i] != '\0'; i++) {
        while (persona.nome[i] >= '0' && persona.cognome[i] <= '9' || persona.cognome[0] == ' '){
            printf("\nErrore, riprova:");
            scanf("%[^\n]s", persona.cognome);
            getchar();
        }
    }

    printf("\nNumero:");
    scanf("%30[^\n]s", persona.numeroDiTelefono);
    getchar();

    for (i = 0; persona.numeroDiTelefono[i] != '\0'; i++) {
        while (!(persona.numeroDiTelefono[i] >= '0' && persona.numeroDiTelefono[i] <= '9')){
            printf("\nErrore, riprova:");
            scanf("%[^\n]s", persona.numeroDiTelefono);
            getchar();
        }
    }

    printf("\nEmail:");
    scanf("%30[^\n]s", persona.email);
    getchar();

    for (i = 0; persona.email[i] != '\0'; i++) {
        while (persona.email [0] == '@'){
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
void acquisisciNome (Contatto persona){
    int i;

    printf("\nNome:");
    scanf("%s", persona.nome);
    getchar();

    for (i = 0; persona.nome[i] != '\0'; i++) {
        while (persona.nome[i] >= '0' && persona.nome[i] <= '9' || persona.nome[0] == ' '){
            printf("\nErrore, riprova:");
            scanf("%s", persona.nome);
            getchar();
        }
    }
}
void acquisisciCognome (Contatto persona){
    int i;
    printf("\nCognome:");
    scanf("%s", persona.cognome);
    getchar();

    for (i = 0; persona.cognome[i] != '\0'; i++) {
        while (persona.nome[i] >= '0' && persona.cognome[i] <= '9' || persona.cognome[0] == ' '){
            printf("\nErrore, riprova:");
            scanf("%s", persona.cognome);
            getchar();
        }
    }
}
void acquisisciNumero (Contatto persona){
    int i;
    printf("\nNumero:");
    scanf("%s", persona.numeroDiTelefono);
    getchar();

    for (i = 0; persona.numeroDiTelefono[i] != '\0'; i++) {
        while (!(persona.numeroDiTelefono[i] >= '0' && persona.numeroDiTelefono[i] <= '9')){
            printf("\nErrore, riprova:");
            scanf("%s", persona.numeroDiTelefono);
            getchar();
        }
    }
}
void acquisisciEmail (Contatto persona){
    int i;
    printf("\nEmail:");
    scanf("%s", persona.email);
    getchar();

    for (i = 0; persona.email[i] != '\0'; i++) {
        while (persona.email [0] == '@'){
            printf("\nErrore, riprova:");
            scanf("%s", persona.email);
            getchar();
        }
    }
}
void acquisisciTipo (Contatto persona){
    printf("\nTipo Contatto:[0=LAVORO, 1=FAMIGLIA, 2=AMICI, 3=ALTRI]");
    scanf("%d", &persona.tipologiaContatto);
    getchar();
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

    printf("\nQuale campo vuoi modificare? [0=Exit, 1=Nome, 2=Cognome, 3=Numero, 4=Email, 5=Tipologia]");
    scanf("%d", &scelta);

    switch (scelta) {
        case 1:
            acquisisciNome(persona);
            break;

        case 2:
            acquisisciCognome(persona);
            break;

        case 3:
            acquisisciNumero(persona);
            break;

        case 4:
            acquisisciEmail(persona);
            break;

        case 5:
            acquisisciTipo(persona);
            break;

        default:
            printf("\nScelta non consentita. Non è stata apportata alcuna modifica.");

    }
    printf("\nModifica eseguita con successo.");
    stampaContatto(persona);

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
}