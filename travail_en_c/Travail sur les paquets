#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    uint8_t dst[6];
    uint8_t src[6];
    uint8_t flags[4];
    uint32_t flag32;
} IPCMv6;

int parse_ipcmv6(const char *buffer, size_t len, IPCMv6 *out) {
    if (len < sizeof(IPCMv6)) return -1;
    memcpy(out->dst, buffer, 6);
    memcpy(out->src, buffer + 6, 6);
    memcpy(out->flags, buffer + 12, 4);
    memcpy(&out->flag32, buffer + 16, 4);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s \"chaine_du_paquet\"\n", argv[0]);
        return 1;
    }

    const char *packet = argv[1];
    size_t packet_len = strlen(packet);

    IPCMv6 info;
    if (parse_ipcmv6(packet, packet_len, &info) == 0) {
        printf("DST: ");
        for (int i = 0; i < 6; i++) printf("%02X ", info.dst[i]);
        printf("\nSRC: ");
        for (int i = 0; i < 6; i++) printf("%02X ", info.src[i]);
        printf("\nFLAGS: ");
        for (int i = 0; i < 4; i++) printf("%02X ", info.flags[i]);
        printf("\nFLAG32: %08X\n", info.flag32);
    } else {
        printf("Paquet trop court !\n");
    }

    return 0;
}
