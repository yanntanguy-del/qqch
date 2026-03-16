#include <stdio.h>      // Pour printf
#include <fcntl.h>      // Pour open
#include <unistd.h>     // Pour read, close
#include <assert.h>     // Pour assert
#include <stdlib.h>     // Pour exit

// Structure simplifiée pour ELF (exemple pédagogique)
struct elf {
    unsigned char e_ident[4]; // Magic ELF (doit contenir 0x7f 'E' 'L' 'F')
    unsigned char nbytes;     // 1=32bits, 2=64bits
    unsigned char endianess;  // 1=LSB, 2=MSB
    unsigned char version;    // Version ELF (exemple: 1)
};

int main(void) {
    struct elf myelffile; // Déclare une variable de type struct elf
    int file;

    // Ouvre le fichier "9mars" en lecture seule
    file = open("9mars", O_RDONLY);
    if (file < 0) {
        // Affiche une erreur si l'ouverture échoue
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Lit le contenu du fichier dans la structure myelffile
    if (read(file, &myelffile, sizeof(myelffile)) != sizeof(myelffile)) {
        // Affiche une erreur si la lecture échoue
        perror("Erreur lors de la lecture du fichier");
        close(file);
        exit(EXIT_FAILURE);
    }

    // Vérifie que le fichier commence bien par la magie ELF
    if (!(myelffile.e_ident[0] == 0x7f && myelffile.e_ident[1] == 'E' && myelffile.e_ident[2] == 'L' && myelffile.e_ident[3] == 'F')) {
        printf("Ce n'est pas un fichier ELF valide.\n");
        close(file);
        exit(EXIT_FAILURE);
    }

    // Affiche le nombre de bits du fichier ELF
    if (myelffile.nbytes == 1)
        printf("Nombre de bits : 32 bits.\n");
    else if (myelffile.nbytes == 2)
        printf("Nombre de bits : 64 bits.\n");
    else
        printf("Nombre de bits : inconnu.\n");

    // Affiche l'endianess (ordre des octets)
    if (myelffile.endianess == 1)
        printf("Endianness : LSB (Little Endian).\n");
    else if (myelffile.endianess == 2)
        printf("Endianness : MSB (Big Endian).\n");
    else
        printf("Endianness : inconnue.\n");

    // Affiche la version ELF (exemple simple)
    printf("Version ELF : %d\n", myelffile.version);

    // Ferme le fichier
    close(file);
    return 0;
}
