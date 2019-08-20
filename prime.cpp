#define cnt 2000000
int prime1[cnt];
int prime2[cnt];
void eratosthenes1()
{
    for (unsigned long i=0; i<cnt; i++)
        prime1[i] = true;
 
    prime1[0] = false;
    prime1[1] = false;
 
    for (unsigned long i=2; i<cnt; i++)
        if (prime1[i])
            for (unsigned long j=i*i; j<cnt; j+=i)
                prime1[j] = false;
}
void eratosthenes2()
{
    for (unsigned long i=0; i<cnt; i++)
        prime2[i] = true;
 
    prime2[0] = false;
    prime2[1] = false;
 
    for (unsigned long i=2; i<cnt; i++)
        if (prime2[i])
		    for (unsigned long k=(cnt-1)/i, j=i*k; k>=i; k--, j-=i)
                if (prime2[k])
                    prime2[j] = false;
}

int main() {
	eratosthenes1();
	eratosthenes2();
    return 0; 
}


