#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cfloat>
#include <cfenv>
#include <cmath>
#include <array>
#include <algorithm>
#include <vector>

namespace std {
int64_t filesInDir(string &fname_template, vector<string > &fnames)
{
    fnames.push_back(fname_template);
    return 1;
}

uint64_t loadPrimesFromFiles(string &fname_template, vector<int64_t > &primes, const int64_t threshold)
{
    vector<string > fnames;
    
    if (filesInDir(fname_template, fnames)) {
        for (size_t idx=0; idx<fnames.size(); idx++) {
            int64_t num;
            string line;
            ifstream fin_primes(fnames[idx]);
            try {
                num = 1;
                while (fin_primes) {
                    fin_primes >> num;
                    if ((num > 0) && (num<threshold)) {
                        primes.push_back(num);
                    }
                    else {
                        fin_primes.close();
                        return primes.size();
                    }
                }
                fin_primes.close();
            }
            catch (exception &e) {
                cerr << "Error: unable to open file " << fnames[idx] << " for reading" << endl;
            }
        }
    }
    return primes.size();
}

class factor {
public:
    int64_t prime;
    int exponent;
    factor() {prime=1; exponent=0;}
    factor(const int64_t p, const int e) {prime=p; exponent=e;}
    
};

int findFactors(const int64_t num, vector<int64_t > &primes, vector<factor > &factors)
{
    int64_t r = num;
    int64_t rootPrime = int64_t(sqrt(num)), prime;
    size_t maxIdx;
    
    factors.clear();    
    // find index to the last prime possible to be a divisor of num
    for (maxIdx=0; maxIdx<primes.size(); maxIdx++) {
        if (primes[maxIdx]>rootPrime) {
            maxIdx--;
            break;
        }
    }
    
    // cout << "largest prime <= " << rootPrime << " is " << primes[maxIdx] << endl;
    
    // find factors of num and their exponents
    while (r != 1) {
        for (size_t idxPrime=0; idxPrime<maxIdx; idxPrime++) {
            prime = primes[idxPrime];
            if ((r % prime) == 0) {
                int idx;
                r /= prime;
                for (idx=1; (r%prime)==0; r/=prime, idx++);
                factors.push_back(factor(prime,idx));
            }
        }
        break;
    }
    if (r!=1) factors.push_back(factor(r, 1));
    return factors.size();
}

int allFactors(vector<factor > &factors, vector<int64_t > &numbers)
{
    numbers.clear();
    for (auto const& f: factors) {
        int64_t num = f.prime;
        size_t sz = numbers.size();
        for (int e=1; e<=f.exponent; e++) {
            numbers.push_back(num);
            for (size_t numsz=0; numsz<sz; numsz++) {
                numbers.push_back(num*numbers[numsz]);
            }
            num*=f.prime;
        }
    }
    return numbers.size();
}

int64_t numOfPrimeFactorsOf8Consecutive(int64_t num, vector<int64_t > &primes, int64_t limit)
{
    vector<int64_t > consecutive;
    vector<int > nfactors;
    vector<factor > factors;
    int num_of_factors = 0;
    int minNF = 0, maxNF = 0;
    
    consecutive.clear();
    nfactors.clear();
    factors.clear();
    
    consecutive.push_back(num); 
    num_of_factors = findFactors(num, primes, factors);
    nfactors.push_back(num_of_factors);
    consecutive.push_back(num+1);
    num_of_factors = findFactors(num+1, primes, factors);
    nfactors.push_back(num_of_factors);
    consecutive.push_back(num+2);
    num_of_factors = findFactors(num+2, primes, factors);
    nfactors.push_back(num_of_factors);
    consecutive.push_back(num+3);
    num_of_factors = findFactors(num+3, primes, factors);
    nfactors.push_back(num_of_factors);
    consecutive.push_back(num+4);
    num_of_factors = findFactors(num+4, primes, factors);
    nfactors.push_back(num_of_factors);
    consecutive.push_back(num+5);
    num_of_factors = findFactors(num+5, primes, factors);
    nfactors.push_back(num_of_factors);
    consecutive.push_back(num+6);
    num_of_factors = findFactors(num+6, primes, factors);
    nfactors.push_back(num_of_factors);
    consecutive.push_back(num+7);
    num_of_factors = findFactors(num+7, primes, factors);
    nfactors.push_back(num_of_factors);
    
    
    // old C++
    int sum_of_num_of_factors = 0;
    for (int i = 0; i < 8; i++)
    {
        sum_of_num_of_factors += nfactors[i];
    }
    minNF = maxNF = sum_of_num_of_factors;
    
    while ((sum_of_num_of_factors != 15) && (num < limit))
    {
        consecutive.erase(consecutive.begin());
        sum_of_num_of_factors -= nfactors[0];
        nfactors.erase(nfactors.begin());
        consecutive.push_back(consecutive[6]+1);
        num_of_factors = findFactors(consecutive[7], primes, factors);
        nfactors.push_back(num_of_factors);
        sum_of_num_of_factors += num_of_factors;
        if (minNF > sum_of_num_of_factors) 
        {
            minNF = sum_of_num_of_factors;
            cout << endl << "n = " << consecutive[0] << " min#F = " << minNF << " max#F = " << maxNF << endl;
        }
        if (maxNF < sum_of_num_of_factors) 
        {
            maxNF = sum_of_num_of_factors;
            cout << endl << "n = " << consecutive[0] << " min#F = " << minNF << " max#F = " << maxNF << endl;
        }
        if ((consecutive[0] % 10000) == 0) cout << ".";
    }
    if (sum_of_num_of_factors == 15)
        return consecutive[0];
    return (-1);
}

}

using namespace std;

vector<factor> myfactors;

int main(int argc, char **argv)
{
    vector<int64_t> primes, numbers;
    string argS("/var/run/user/1000/primesTo10M.txt");
    int64_t number;
    
    loadPrimesFromFiles(argS, primes, 64*1024);
    cout << "Number of primes loaded: " << primes.size() << endl;
    number = numOfPrimeFactorsOf8Consecutive(8747, primes, 10000000);
    if (number < 10000000)
    {
        cout << "n = " << number << endl;
    }
	return 0;
}

