#define SIZE 50
//
int isDigit(char c)
{
	return (c >= '0' && c <='9');
}

int isValid(char *exp)
{
	char *p = exp;
	while(*p == 'F' || *p == 'G' || *p == '(' || *p == ')' || *p == ' ' || *p == ',' || isDigit(*p))
		*p++;
	return *p == '\0';
}

int eval(int *i, char *exp)
{
	// Looking for F, G or a digit
	while(exp[*i] != 'F' && exp[*i] != 'G' && !isDigit(exp[*i]))
		*i += 1;
	if (exp[*i] == 'F' || exp[*i] == 'G')
	{
		*i += 1;
		return (exp[*i - 1] == 'F') ? 3 * eval(i, exp) + 1 : eval(i, exp) * eval(i, exp) - 3;  
	}

	int n = 0;
	while(isDigit(exp[*i]))
	{
		n += exp[*i] - '0';
		*i += 1;
	}

	return n;
}

int main()
{
	char exp[SIZE] = "";
	int i = 0;

	gets(exp);
	if (isValid(exp))
		printf("%d\n", eval(&i, exp));
	else
		printf("Invalid expression\n");

	return 0;
}