#include "SortingAlgorithm.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace SortLibrary;
using namespace std;



int main()
{
    cout<< "please enter size of the vector, in which perform the test:";
    size_t size;
    cin>> size;

    vector< unsigned int> v_ord(size);
    vector<unsigned int> v_pert(size);
    vector<unsigned int> v_dec(size);
    vector<unsigned int> v_rand(size);

    unsigned int n = 0;
    generate(v_ord.begin(), v_ord.end(), [&n] () {return n++;});
    n = 0;
    generate(v_pert.begin(), v_pert.end(), [&n] () {return n++;});
    n = size;
    generate(v_dec.begin(), v_dec.end(), [&n] () {return n--;});

    generate(v_rand.begin(), v_rand.end(), [] () {return rand();});

    for (unsigned int i = 0; i<2; i++)
        v_pert[i] = rand() % 1000; //restituisce numeri interi distribuiti tra 0 e RAND_MAX. per normalizzare, divido per RAND_MAX


    //ordered case
    double mergesort_ave = 0;
    double bubblesort_ave = 0;

    unsigned int sample_size = 1000;
    for (unsigned int i = 0; i< sample_size;i++){
        //testing mergesort
        chrono::steady_clock::time_point t_begin_merge = chrono::steady_clock::now();

        MergeSort(v_ord);

        chrono::steady_clock::time_point t_end_merge = chrono::steady_clock::now();
        double timeElapsed_merge = chrono::duration_cast<chrono::microseconds>(t_end_merge - t_begin_merge).count();
        mergesort_ave = (mergesort_ave*i + timeElapsed_merge)/(i+1);

        //testing bubblesort
        chrono::steady_clock::time_point t_begin_bubble = chrono::steady_clock::now();

        BubbleSort(v_ord);

        chrono::steady_clock::time_point t_end_bubble = chrono::steady_clock::now();
        double timeElapsed_bubble = chrono::duration_cast<chrono::microseconds>(t_end_bubble - t_begin_bubble).count();
        bubblesort_ave = (bubblesort_ave*i + timeElapsed_bubble)/(i+1);



    }
    cout<<"Average  time in microseconds of mergesort over an increasingly ordered vector of size "
         <<size <<" after having taken "<<sample_size<<" samples: "<<mergesort_ave<< endl;
    cout<<"Average  time in microseconds of bubblesort over an increasingly ordered vector of size "
         <<size <<" after having taken "<<sample_size<<" samples: "<<bubblesort_ave<<endl;


     //perturbed case
    mergesort_ave = 0;
    bubblesort_ave = 0;


    for (unsigned int i = 0; i< sample_size;i++){
        //testing mergesort
        chrono::steady_clock::time_point t_begin_merge = chrono::steady_clock::now();

        MergeSort(v_pert);

        chrono::steady_clock::time_point t_end_merge = chrono::steady_clock::now();
        double timeElapsed_merge = chrono::duration_cast<chrono::microseconds>(t_end_merge - t_begin_merge).count();
        mergesort_ave = (mergesort_ave*i + timeElapsed_merge)/(i+1);

        //testing bubblesort
        chrono::steady_clock::time_point t_begin_bubble = chrono::steady_clock::now();

        BubbleSort(v_pert);

        chrono::steady_clock::time_point t_end_bubble = chrono::steady_clock::now();
        double timeElapsed_bubble = chrono::duration_cast<chrono::microseconds>(t_end_bubble - t_begin_bubble).count();
        bubblesort_ave = (bubblesort_ave*i + timeElapsed_bubble)/(i+1);

    }
    cout<<"Average  time in microseconds of mergesort over a slightly perturbated ordered vector of size "
         <<size <<" after having taken "<<sample_size<<" samples: "<<mergesort_ave<< endl;
    cout<<"Average  time in microseconds of bubblesort over slightly perturbated ordered vector of size "
         <<size <<" after having taken "<<sample_size<<" samples: "<<bubblesort_ave<<endl;

    //decreasingly ordered case
    mergesort_ave = 0;
    bubblesort_ave = 0;


    for (unsigned int i = 0; i< sample_size;i++){
        //testing mergesort
        chrono::steady_clock::time_point t_begin_merge = chrono::steady_clock::now();

        MergeSort(v_ord);

        chrono::steady_clock::time_point t_end_merge = chrono::steady_clock::now();
        double timeElapsed_merge = chrono::duration_cast<chrono::microseconds>(t_end_merge - t_begin_merge).count();
        mergesort_ave = (mergesort_ave*i + timeElapsed_merge)/(i+1);

        //testing bubblesort
        chrono::steady_clock::time_point t_begin_bubble = chrono::steady_clock::now();

        BubbleSort(v_ord);

        chrono::steady_clock::time_point t_end_bubble = chrono::steady_clock::now();
        double timeElapsed_bubble = chrono::duration_cast<chrono::microseconds>(t_end_bubble - t_begin_bubble).count();
        bubblesort_ave = (bubblesort_ave*i + timeElapsed_bubble)/(i+1);

    }
    cout<<"Average  time in microseconds of mergesort over a decreasingly ordered vector of size "
         <<size <<" after having taken "<<sample_size<<" samples: "<<mergesort_ave<< endl;
    cout<<"Average  time in microseconds of bubblesort over a decreasingly ordered vector of size "
         <<size <<" after having taken "<<sample_size<<" samples: "<<bubblesort_ave<<endl;

    //random case
    mergesort_ave = 0;
    bubblesort_ave = 0;


    for (unsigned int i = 0; i< sample_size;i++){
        //testing mergesort
        chrono::steady_clock::time_point t_begin_merge = chrono::steady_clock::now();

        MergeSort(v_rand);

        chrono::steady_clock::time_point t_end_merge = chrono::steady_clock::now();
        double timeElapsed_merge = chrono::duration_cast<chrono::microseconds>(t_end_merge - t_begin_merge).count();
        mergesort_ave = (mergesort_ave*i + timeElapsed_merge)/(i+1);

        //testing bubblesort
        chrono::steady_clock::time_point t_begin_bubble = chrono::steady_clock::now();

        BubbleSort(v_rand);

        chrono::steady_clock::time_point t_end_bubble = chrono::steady_clock::now();
        double timeElapsed_bubble = chrono::duration_cast<chrono::microseconds>(t_end_bubble - t_begin_bubble).count();
        bubblesort_ave = (bubblesort_ave*i + timeElapsed_bubble)/(i+1);

    }
    cout<<"Average  time in microseconds of mergesort over a decreasingly ordered vector of size "
         <<size <<" after having taken "<<sample_size<<" samples: "<<mergesort_ave<< endl;
    cout<<"Average  time in microseconds of bubblesort over a decreasingly ordered vector of size "
         <<size <<" after having taken "<<sample_size<<" samples: "<<bubblesort_ave<<endl;







    return 0;
}

