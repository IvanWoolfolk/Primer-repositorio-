
void delay(int Nseconds);

void main2   (	void	)
{
	int t=0;
	while(t!=3)
	{
		printf("\n Moviendose \n");
		t+=1;
		delay(1);
	}
}

void delay(int Nseconds)
{
	int milli_seconds= 1000	* Nseconds;

	clock_t start_time = clock();

	while(clock()	<	start_time	+	milli_seconds)
		;
}