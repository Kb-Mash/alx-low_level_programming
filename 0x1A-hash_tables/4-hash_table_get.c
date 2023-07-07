#include "hash_tables.h"

/**
 * hash_table_get - retrieves the value associated with
 * a key in a hash table.
 * @ht: A pointer to the hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *head;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (ht->array[index] && !strcmp(ht->array[index]->key, key))
		return (ht->array[index]->value);
	for (head = ht->array[index]; head; head = head->next)
	{
		if (!strcmp(head->key, key))
			return (head->value);
	}
	return (NULL);
}
