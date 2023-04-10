#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * main - displays the information contained in the ELF header at the start
 * of an ELF file.
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 on success, otherwise 98
 */
int main(int argc, char **argv)
{
        int fd, ret;
        Elf64_Ehdr header;
        unsigned char magic[4] = {0x7f, 0x45, 0x4c, 0x46};

        if (argc != 2)
        {
                dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
                exit(98);
        }

        fd = open(argv[1], O_RDONLY);
        if (fd == -1)
        {
                dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
                exit(98);
        }

        ret = read(fd, &header, sizeof(header));
        if (ret == -1)
        {
                dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
                close(fd);
                exit(98);
        }

        if (header.e_ident[0] != magic[0] || header.e_ident[1] != magic[1] ||
            header.e_ident[2] != magic[2] || header.e_ident[3] != magic[3])
        {
                dprintf(STDERR_FILENO, "Error: Not an ELF file - it has the wrong magic bytes\n");
                close(fd);
                exit(98);
        }

        printf("ELF Header:\n");

        printf("  Magic:   ");
        for (int i = 0; i < EI_NIDENT; i++)
                printf("%02x ", header.e_ident[i]);
        printf("\n");

        printf("  Class:                             ");
        if (header.e_ident[EI_CLASS] == ELFCLASS32)
                printf("ELF32\n");
        else if (header.e_ident[EI_CLASS] == ELFCLASS64)
                printf("ELF64\n");
        else
                printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);

        printf("  Data:                              ");
        if (header.e_ident[EI_DATA] == ELFDATA2LSB)
                printf("2's complement, little endian\n");
        else if (header.e_ident[EI_DATA] == ELFDATA2MSB)
                printf("2's complement, big endian\n");
        else
                printf("<unknown: %x>\n", header.e_ident[EI_DATA]);

        printf("  Version:                           %d (current)\n",
               header.e_ident[EI_VERSION]);

        printf("  OS/ABI:                            ");
        switch (header.e_ident[EI_OSABI])
        {
        case ELFOSABI_SYSV:
                printf("UNIX - System V\n");
                break;
        case ELFOSABI_LINUX:
                printf("UNIX - Linux\n");
                break;
        case ELFOSABI_SOLARIS:
                printf("UNIX - Solaris\n");
                break;
        case ELFOSABI_FREEBSD:
                printf("UNIX - FreeBSD\n");
                break;
        case ELFOSABI_NETBSD:
                printf("UNIX - NetBSD\n");
                break;
        case ELFOSABI_OPENBSD:
                printf("UNIX - OpenBSD\n");
                break;
        case ELFOSABI_ARM:
                printf("
