#include <bits/stdc++.h>
using namespace std;


typedef struct SF_time{
	int s;
	int f;
}SF_time;
bool compare(SF_time a , SF_time b) {
	return (a.f < b.f);
}
int main()
{
	int i,n,s,f;
	scanf("%d", &n);
	vector<SF_time>tmp;
	tmp.resize(n);
	vector<SF_time>job;
	job.resize(n);
	
	for(i = 0; i < n; i++) {
		scanf("%d%d", &s,&f);
		tmp[i].s = s;
		tmp[i].f = f;
	}
	
	sort(tmp.begin() , tmp.end(), compare);
	
	int count = 1;
	int cf = tmp[0].f;
	job[0].s = tmp[0].s;
	job[0].f = cf;
	for(i = 1; i < n; i++){
		if(tmp[i].s >= cf){
			cf = tmp[i].f;
			job[count].s = tmp[i].s;
			job[count].f = cf;
			count++;
		}
	}
	cout<<"maximum scheduled job is  = "<<count<<endl;
	cout<<"and job's are"<<endl;
	for(i = 0; i < count; i++)
	cout<<"job "<<i+1<<" start = "<<job[i].s<<" end = "<<job[i].f<<endl;
	
return 0;
}
