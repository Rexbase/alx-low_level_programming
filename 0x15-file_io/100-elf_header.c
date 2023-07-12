#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_error(const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void print_magic(unsigned char *e_ident)
{
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", e_ident[i]);
    printf("\n");
}

void print_class(unsigned char e_ident)
{
    printf("Class:   ");
    switch (e_ident)
    {
        case ELFCLASSNONE:
            printf("None\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            print_error("Invalid ELF class");
    }
}

void print_data(unsigned char e_ident)
{
    printf("Data:    ");
    switch (e_ident)
    {
        case ELFDATANONE:
            printf("None\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            print_error("Invalid ELF data encoding");
    }
}

void print_version(unsigned char e_ident)
{
    printf("Version: ");
    switch (e_ident)
    {
        case EV_NONE:
            printf("Invalid version\n");
            break;
        case EV_CURRENT:
            printf("Current version\n");
            break;
        default:
            printf("Unknown version\n");
    }
}

void print_osabi(unsigned char e_ident)
{
    printf("OS/ABI:  ");
    switch (e_ident)
    {
        case ELFOSABI_NONE:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
        default:
            printf("Other\n");
    }
}

void print_abi_version(unsigned char e_ident)
{
    printf("ABI Version: %d\n", e_ident);
}

void print_type(unsigned int e_type)
{
    printf("Type:    ");
    switch (e_type)
    {
        case ET_NONE:
            printf("No file type\n");
            break;
        case ET_REL:
            printf("Relocatable file\n");
            break;
        case ET_EXEC:
            printf("Executable file\n");
            break;
        case ET_DYN:
            printf("Shared object file\n");
            break;
        case ET_CORE:
            printf("Core file\n");
            break;
        default:
            printf("Unknown file type\n");
    }
}

void print_entry(unsigned long int e_entry)
{
    printf("Entry point address: %#lx\n", e_entry);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        print_error("Cannot open ELF file");

    Elf64_Ehdr header;
    if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
        print_error("Cannot read ELF header");

    // Verify ELF magic numbers
    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
        print_error("Not an ELF file");

    // Print ELF header information
    print_magic(header.e_ident);
    print_class(header.e_ident[EI_CLASS]);
    print_data(header.e_ident[EI_DATA]);
    print_version(header.e_ident[EI_VERSION]);
    print_osabi(header.e_ident[EI_OSABI]);
    print_abi_version(header.e_ident[EI_ABIVERSION]);
    print_type(header.e_type);
    print_entry(header.e_entry);

    close(fd);
    return 0;
}
