#include "main.h"

int _strlen(char *s);
int check_palindrome(char *s, int len, int i);

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to be checked
 * Return: 1 (success), 1 (fail)
 */

int is_palindrome(char *s)
{
	int i = 0;
	int len = _strlen(s);

	if (!(*s))
		return (1);

	return (check_palindrome(s, len, i));
}


/**
 * _strlen - returns the length of a string
 * @s: string to be measured
 * Return: length of the string
 */

int _strlen(char *s)
{
	int len = 0;

	if (*s)
	{
		len++;
		len += _strlen(s + 1);
	}

	return (len);
}

/**
 * check_palindrome - checks if a string is a palindrome
 * @s: string to be checked
 * @len: length of s
 * @i: index of the string to be checked
 * Return: 1 (success), 0 (fail)
 */

int check_palindrome(char *s, int len, int i)
{
	if (s[i] == s[len / 2])
		return (1);

	if (s[i] == s[len - i - 1])
		return (check_palindrome(s, len, i + 1));

	return (0);
}
