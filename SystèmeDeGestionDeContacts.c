#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char Nom[50];
    char Telephon[50];
    char Email[50];
} Contact;

void ajouter_contact(Contact contacts[], int *n) {
    printf("\n========== Ajouter un nouveau contact ==========\n");
    printf("Nom : ");
    scanf(" %[^\n]s", contacts[*n].Nom);

    printf("Numéro de téléphone: ");
    scanf(" %s", contacts[*n].Telephon);

    printf("Adresse e-mail: ");
    scanf(" %s", contacts[*n].Email);

    (*n)++;
    printf("\n✅ Contact ajouté avec succès!\n");
}

void modifier_contact(Contact contacts[], int n) {
    char Nom[50];
    int ifTrouve = 0;

    printf("\n========== Modifier un contact ==========\n");
    printf("Entrer le nom du contact à modifier: ");
    scanf(" %[^\n]s", Nom);

    for (int i = 0; i < n; i++) {
        if (strcmp(contacts[i].Nom, Nom) == 0) {
            ifTrouve = 1;

            printf("Modifier le numéro de téléphone: ");
            scanf(" %s", contacts[i].Telephon);
            printf("Modifier l'adresse e-mail: ");
            scanf(" %s", contacts[i].Email);
            printf("\n✅ Le contact a été modifié avec succès.\n");
            break;
        }
    }

    if (!ifTrouve)
        printf("\n❌ Contact non trouvé.\n");
}

void supprimer_contact(Contact contacts[], int *n) {
    char Nom[50];
    int Iftrouve = 0;

    printf("\n========== Supprimer un contact ==========\n");
    printf("Entrer le nom du contact à supprimer: ");
    scanf(" %[^\n]s", Nom);

    for (int i = 0; i < *n; i++) {
        if (strcmp(contacts[i].Nom, Nom) == 0) {
            Iftrouve = 1;

            for (int j = i; j < *n - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*n)--;
            printf("\n✅ Le contact a été supprimé avec succès.\n");
            break;
        }
    }

    if (!Iftrouve)
        printf("\n❌ Contact non trouvé.\n");
}

void afficher_contacts(Contact contacts[], int n) {
    if (n == 0) {
        printf("\n⚠️ Aucun contact à afficher.\n");
        return;
    }

    printf("\n========== Liste des contacts ==========\n");

    for (int i = 0; i < n; i++) {
        printf("\n----------------------------------------\n");
        printf("Nom      : %s\n", contacts[i].Nom);
        printf("Téléphone: %s\n", contacts[i].Telephon);
        printf("E-mail   : %s\n", contacts[i].Email);
        printf("----------------------------------------\n");
    }
}

void rechercher_contact(Contact contacts[], int n, char Nom[]) {
    int ifTrouve = 0;

    printf("\n========== Recherche de contact ==========\n");
    for (int i = 0; i < n; i++) {
        if (strcasecmp(contacts[i].Nom, Nom) == 0) {
            printf("\n✅ Contact trouvé:\n");
            printf("\n----------------------------------------\n");
            printf("Nom      : %s\n", contacts[i].Nom);
            printf("Téléphone: %s\n", contacts[i].Telephon);
            printf("E-mail   : %s\n", contacts[i].Email);
            printf("----------------------------------------\n");

            ifTrouve = 1;
            break;
        }
    }

    if (!ifTrouve) {
        printf("\n❌ Contact non trouvé.\n");
    }
}

void Sorting_contact(Contact contacts[], int n) {
    Contact swap;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(contacts[i].Nom, contacts[j].Nom) > 0) {
                swap = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = swap;
            }
        }
    }
    printf("\n✅ Les contacts sont triés par nom.\n");
}

void menu_contacts() {
    Contact contacts[100];
    int n = 0;
    int choix;

    while (1) {
        printf("\n========== Menu de gestion de contacts ==========\n");
        printf("1. ➕ Ajouter un contact\n");
        printf("2. ✏️ Modifier un contact\n");
        printf("3. ❌ Supprimer un contact\n");
        printf("4. 📋 Afficher tous les contacts\n");
        printf("5. 🔍 Rechercher un contact\n");
        printf("6. 🔄 Trier les contacts\n");
        printf("7. 🚪 Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        if (choix < 1 || choix > 7) {
            printf("\n⚠️ Choix invalide. Veuillez essayer à nouveau.\n");
            continue;
        }

        switch (choix) {
            case 1:
                ajouter_contact(contacts, &n);
                break;
            case 2:
                modifier_contact(contacts, n);
                break;
            case 3:
                supprimer_contact(contacts, &n);
                break;
            case 4:
                afficher_contacts(contacts, n);
                break;
            case 5: {
                char Nom[50];
                printf("Entrez le nom à rechercher: ");
                scanf(" %[^\n]s", Nom);
                rechercher_contact(contacts, n, Nom);
                break;
            }
            case 6:
                Sorting_contact(contacts, n);
                break;
            case 7:
                printf("\n🚪 Quitter le programme. Merci d'avoir utilisé le système de gestion de contacts!\n");
                return;
        }
    }
}

int main() {
    menu_contacts();
    return 0;
}
