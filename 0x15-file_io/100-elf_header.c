#include "main.h"
#include <elf.h>
#include <stdio.h>

void _magic(unsigned char *e_ident);
void _class(unsigned char *e_ident);
void _data(unsigned char *e_ident);
void _version(unsigned char *e_ident);
void _abi(unsigned char *e_ident);
void _osabi(unsigned char *e_ident);
void _type(unsigned int e_type, unsigned char *e_ident);
void _entry(unsigned long int e_entry, unsigned char *e_ident);
void _close(int fd);
void is_elf(unsigned char *e_ident);
void print_elf(Elf64_Ehdr *ptr);

/**
 * main - entry point
 * @ac: number of arguments
 * @av: array of pointers to the arguments
 * Return: 0 (success)
 */
int main(int __attribute__((__unused__)) ac, char *av[])
{
	/* Elf64_Ehdr structure */
	Elf64_Ehdr *ptr;
	int fd;
	ssize_t r;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}

	ptr = malloc(sizeof(Elf64_Ehdr));
	if (!ptr)
	{
		_close(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}

	r = read(fd, ptr, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(ptr);
		_close(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", av[1]);
		exit(98);
	}

	print_elf(ptr);

	free(ptr);
	_close(fd);

	return (0);
}

/**
 * print_elf - prints the information contained in the
 * ELF header at the start of an ELF file
 * @ptr: pointer to members of Elf64_Ehdr struct
 */
void print_elf(Elf64_Ehdr *ptr)
{
	is_elf(ptr->e_ident);
	printf("ELF Header:\n");
	_magic(ptr->e_ident);
	_class(ptr->e_ident);
	_data(ptr->e_ident);
	_version(ptr->e_ident);
	_osabi(ptr->e_ident);
	_abi(ptr->e_ident);
	_type(ptr->e_type, ptr->e_ident);
	_entry(ptr->e_entry, ptr->e_ident);
}

/**
 * _magic - prints the magic numbers
 * @e_ident: An array of 16 bytes containing information about the ELF file
 */
void _magic(unsigned char *e_ident)
{
	int i = 0;

	printf("  Magic:   ");

	while (i < EI_NIDENT)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
		i++;
	}
}

/**
 * _class - prints the class
 * @e_ident: An array of 16 bytes containing information about the ELF file
 */
void _class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * _data - prints the data
 * @e_ident: An array of 16 bytes containing information about the ELF file
 */
void _data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * _version - prints the version
 * @e_ident: An array of 16 bytes containing information about the ELF file
 */
void _version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * _osabi - prints the OS/ABI of an ELF header
 * @e_ident: An array of 16 bytes containing information about the ELF file
 */
void _osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * _abi - prints the ABI version
 * @e_ident: An array of 16 bytes containing information about the ELF file
 */
void _abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * _type - prints the type
 * @e_type: ELF type
 * @e_ident: An array of 16 bytes containing information about the ELF file
 */
void _type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * _entry - prints the entry point address
 * @e_entry: address of the ELF entry point
 * @e_ident: An array of 16 bytes containing information about the ELF file
 */
void _entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * _close - closes file
 * @fd: file descriptor
 */
void _close(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
}

/**
 * is_elf - checks if a file is an ELF file
 * @e_ident: An array of 16 bytes containing information about the ELF file
 */
void is_elf(unsigned char *e_ident)
{
	int i = 0;

	while (i < 4)
	{
		if (e_ident[i] != 127 &&
		    e_ident[i] != 'E' &&
		    e_ident[i] != 'L' &&
		    e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
		i++;
	}
}
