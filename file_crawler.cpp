#include<bits/stdc++.h>
using namespace std;
class FileCrawler{

	vector<string>path;
	vector<string>v[100000];
public:
	void Crawling();
	void Search(string word);
	void storingfile(string file); 

};
void FileCrawler::storingfile(string file)
{
	path.push_back(file);
}

void FileCrawler::Crawling()
{
	for(int i=0;i<path.size();i++)
	{
			fstream f;
			f.open(path[i].c_str());
			string word;
			
			while(f>>word)
			{
				v[i].push_back(word);
				//cout<<word<<endl;
			}
			f.close();
	}
	//cout<<path.size();
}

void FileCrawler::Search(string word)
{
	//cout<<word<<" is present in: \n";
	vector<pair<int,int>>ans;
	for(int i=0;i<path.size();i++)
	{
		int c=0;
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j]==word)
			{
				c++;
			}
			//cout<<i<<" "<<j<<endl;
		}
		if(c!=0)
		{
			ans.push_back({i,c});
		}
	}
	if(ans.size()==0){cout<<"Word is not present in any file\n";}
	else{
		cout<<word<<" is present in: \n";
		for(int i=0;i<ans.size();i++)
		{
			cout<<path[ans[i].first]<<" file "<<ans[i].second<<" times"<<endl;
		}
	}		
}
int main()
{
	cout<<"Enter number of files to enter: ";
	int n;cin>>n;
	cout<<"Enter each file name one by one: \n";
	FileCrawler *filecrawler=new FileCrawler;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		filecrawler->storingfile(s);
	}
	filecrawler->Crawling();

	cout<<"Crawling finished\n";
	string c,word;

	cout<<"Do u want to search a word: ";
	cin>>c;
	while(c!="No" && c!="no")
	{
		cout<<"Enter the word: ";
		cin>>word;
		filecrawler->Search(word);
		cout<<"Do u want to search another word: ";
		cin>>c;
	}

}