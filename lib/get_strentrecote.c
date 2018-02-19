#include <stdlib.h>

int len_entrecote(char *str)
{
	int i = 0;

	for(int i = 0; str[i] != '\"'; i++);
	return (++i);
}

char *get_strentrecote(char *str)
{
	int j = 0;
	char *tmp;

	if (str == NULL)
		return (NULL);
	for (; str[0] != '\"' && str[0] != '\0'; str++);
	tmp = malloc(sizeof(char) * (len_entrecote(str) + 2));
	if (tmp == NULL)
		return (NULL);
	for (++str; str[0] != '"' && str[0] != '\0'; str++) {
		tmp[j] = str[0];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

int main(void) {
	printf("%s\n", get_strentrecote("efzef \"bitefe\" fe"));
	return (0);
}
