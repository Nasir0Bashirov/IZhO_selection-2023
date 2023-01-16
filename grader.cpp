#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include "books.h"

using namespace std;

namespace {
struct Judge
{
	int N;
	int A[1002];
	int pos[1002];
	bool f[1002];
	int query_c;
	bool answered;
	void init()
	{
		query_c=0;
		int ret=scanf("%d",&N); ret++;
		answered=false;
		for(int i=0;i<N;i++)ret=scanf("%d",&A[i]),pos[A[i]]=i;
	}
	int query(const vector<int>& S)
	{
		if(query_c==20000)
		{
			puts("Wrong Answer [Query limit exceeded]");
			exit(0);
		}
		if(int(S.size())!=N)
		{
			puts("Wrong Answer [Incorrect size of S]");
			exit(0);
		}
		bool all_zero=true;
		for(int i=0;i<N;i++)
		{
			if(S[i]!=0&&S[i]!=1)
			{
				puts("Wrong Answer [Unintended value]");
				exit(0);
			}
			if(S[i]==1)all_zero=false;
		}
		if(all_zero)
		{
			puts("Wrong Answer [Empty request]");
			exit(0);
		}
		memset(f,0,sizeof(f));
		for(int i=0;i<N;i++)if(S[i])f[pos[i+1]]=true;
		bool las=false;
		int r=0;
		for(int i=0;i<N;i++)
		{
			if(las==false&&f[i]==true)r++;
			las=f[i];
		}
		query_c++;
		return r;
	}
	void answer(const vector<int>& R)
	{
		bool f1=true,f2=true;
		if(int(R.size())!=N)
		{
			puts("Wrong Answer　[Incorrect size of R]");
			exit(0);
		}
		if(answered)
		{
			puts("Wrong Answer [Answer() function called more than once]");
			exit(0);
		}
		answered=true;
		memset(f,0,sizeof(f));
		for(int i=0;i<N;i++)
		{
			if(R[i]<=0||R[i]>N)
			{
				puts("Wrong Answer [Wrong book ID]");
				exit(0);
			}
			if(f[R[i]])
			{
				puts("Wrong Answer [Dublicate book ID]");
				exit(0);
			}
			f[R[i]]=true;
		}
		for(int i=0;i<N;i++)
		{
			f1&=A[i]==R[i];
			f2&=A[i]==R[N-i-1];
		}
		if(!f1&&!f2)
		{
			puts("Wrong Answer　[Answer is not correct]");
			exit(0);
		}
	}
	void end()
	{
		if(!answered)puts("Wrong Answer [You did not call function Answer()]");
		else printf("Accepted : You made %d queries\n",query_c);
	}
}judge;
}

int Query(const vector<int>& S)
{
	return judge.query(S);
}
void Answer(const vector<int>& R)
{
	judge.answer(R);
}

int main()
{
	judge.init();
	Solve(judge.N);
	judge.end();
}
