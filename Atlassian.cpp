/*
string winner(vector<string>alice, vector<string>bob){

    int alice_score = 0;
    int bob_score = 0;
    for(int i=0; i<alice.size(); i++){
        if(alice[i]=="E") alice_score++;
        else if(alice[i]=="M") alice_score+=3;
        else alice_score+=5; 
    }

    for(int i=0; i<bob.size(); i++){
        if(bob[i]=="E") bob_score++;
        else if(bob[i]=="M") bob_score+=3;
        else bob_score+=5; 
    }

    if(bob_score > alice_score) return "Bob";
    else if(bob_score < alice_score) return "Alice";
    else return "Tie";
}
*/
/*


void func(vector<int> &weights, vector<int> &M, int maxCapacity, int start, int end, int curr=0)
{
	if(curr>maxCapacity)
		return;
	if(start==end)
	{
		M.push_back(curr);
		return;
	}
	func(weights,M,maxCapacity,start+1,end,curr+weights[start]);
	func(weights,M,maxCapacity,start+1,end,curr);
}
int weightCapacity(vector<int> weights, int maxCapacity)
{
	vector<int> M1,M2;
	int N=weights.size();
	func(weights,M1,maxCapacity,0,N/2);
	func(weights,M2,maxCapacity,N/2+1,N-1);

	sort(M1.begin(),M1.end());
	sort(M2.begin(),M2.end());
	int ans=0;
	for(int i=0;i<M1.size();i++)
	{
		int index = upper_bound(M2.begin(),M2.end(),maxCapacity-M1[i])-M2.begin();
		index--;
		ans=max(ans,M2[index]+M1[i]);
	}
	return ans;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	vector<int>weights(n+1);
	weights[0]=0;
	for(int i=1; i<=n; i++) cin>>weights[i];
	int maxCap; 
	cin>>maxCap;
	vector<vector<int>>dp(n+1,vector<int>(maxCap+1,0)); 

	for(int i=1; i<=n; i++){
		for(int j=1; j<=maxCap; j++){

			int exclude = dp[i-1][j];
			int include = 0;
			if(weights[i] <= j){
				include = weights[i] + dp[i-1][j-weights[i]];
			}
			dp[i][j] = max(include,exclude); 
		}
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=maxCap; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl; 
	}
	cout << dp[n][maxCap] << endl; 
}
*/

#include <bits/stdc++.h>
using namespace std;
long long M=1000000007;
long long expo(long long X, long long N)
{
	if(N==0)
		return 1;
	if(N%2==0)
		return expo((X*X)%M,N/2);
	return (X*expo(X,N-1))%M;
}

int getCount(int n, int low, int high)
{
	int num=high-low+1,e,o;
	if(num%2==0)
	{
		e=num/2;
		o=num/2;
	}
	else
	{
		if(low%2==0)
		{
			e=num/2+1;
			o=num/2;
		}
		else
		{
			e=num/2;
			o=num/2+1;
		}
	}
	return (((expo(e+o,n)+expo(abs(e-o),n))%M)*expo(2,M-2))%M;
}

[1] Applications of image captioning. https://velement.io/image-captioning- applications/.
[2] Flickr 8k dataset by university of illinois at urbana-champaign. https://forms.illinois.edu/sec/1713398.
[3] Google images. https://en.wikipedia.org/wiki/Google Images.
[4] Image captioning with keras. https://towardsdatascience.com/image- captioning-with-keras-teaching-computers-to-describe-pictures- c88a46a311b8.
[5] ADRAKATTI, A., WODEYAR, R., AND K.R, M. Search by image: A novel approach to content based image retrieval system. International Journal of Library Science 14 (09 2016), 41–47.
[6] ALKHAWLANI, M., ELMOGY, M., AND EL-BAKRY, H. Text-based, content-based, and semantic-based image retrievals: A survey. Inter- national Journal of Computer and Information Technology 4 (01 2015), 58–66.
[7] BAI, S., AND AN, S. A survey on automatic image caption generation. Neurocomputing 311 (2018), 291–304.
[8] BALUJA, S., AND JING, Y. Visualrank: Applying pagerank to large- scale image search. IEEE Transactions on Pattern Analysis and Machine Intelligence 30 (11 2008), 1877–1890.
[9] BEN-HAIM, N., BABENKO, B., AND BELONGIE, S. Improvingweb- based image search via content based clustering. In 2006 Conference on Computer Vision and Pattern Recognition Workshop (CVPRW’06) (2006), pp. 106–106.
[10] CHUTEL, P. M., AND SAKHARE, A. V. Evaluation of compact compos- ite descriptor based reverse image search. 2014 International Conference on Communication and Signal Processing (2014), 1430–1434.
[11] EDISON, T. J. Image-based indexing and classification in image databases, U.S. Patent 7 787 711 B2, Aug. 31, 2010.
[12] GANJU, S. Exploration of image captioning datasets. http://sidgan.me/technical/2016/01/09/Exploring-Datasets.
[13] GRAUMAN,K.Efficientlysearchingforsimilarimages.Commun.ACM 53 (2010), 84–94.
[14] GU, J., WANG, G., CAI, J., AND CHEN, T. An empirical study of language cnn for image captioning. In 2017 IEEE International Conference on Computer Vision (ICCV) (2017), pp. 1231–1240.
[15] GUO, T., CHANG, S., YU, M., AND BAI, K. Improving reinforcement learning based image captioning with natural language prior. In Proceedings of the 2018 Conference on Empirical Methods in Natural Language Processing (Brussels, Belgium, Oct.-Nov. 2018), Association for Computational Linguistics, pp. 751–756.
[16] JING, Y., AND BALUJA, S. Pagerank for product image search. In
Proceedings of the 17th International Conference on World Wide Web
(New York, NY, USA, 2008), WWW ’08, Association for Computing
Machinery, p. 307–316.
[17] LUO, B., WANG, X., AND TANG, X. World wide web based image
search engine using text and image content features. Proc SPIE (01
2003).
[18] SOH, M. Learning cnn-lstm architectures for image caption generation.
Neurocomputing (2016).
[19] SUN, J., LAPUSCHKIN, S., SAMEK, W., AND BINDER, A. Under-
standing image captioning models beyond visualizing attention. ArXiv abs/2001.01037 (2020).