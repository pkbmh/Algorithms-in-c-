#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s1[1000];
	char s2[1000];
	vector<char>seq;
	scanf("%s%s",s1,s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);

	int tab[len1+1][len2+1];

	int i,j;
	for(i = 0; i <= len1; i++)
	tab[i][0] = 0;

	for(i = 0; i <= len2; i++)
	tab[0][i] = 0;


	for(i = 1; i <= len1; i++) {
	int flag = 1;
		for(j = 1; j <= len2; j++) {
					;
			if(s1[i-1] == s2[j-1]) {
			tab[i][j] = tab[i-1][j-1]+1;
				if(flag){
				seq.push_back(s1[i-1]);
				flag = 0;

				}
			}

			else tab[i][j] = max(tab[i-1][j] , tab[i][j-1]);
		}
	}

	printf("Longest common subsequence is length of = %d\n", tab[len1][len2]);

	/*for(i = 0; i < seq.size(); i++)
	cout << seq[i];
    */
	cout << endl;

return 0;
}
