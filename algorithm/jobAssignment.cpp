#include<bits/stdc++.h>

using namespace std;


class ScoreList{
    public:
        int employee;
        int job;
        double score;
        ScoreList(int employee, int job, double score){
            this->employee = employee;
            this->job = job;
            this->score = score;
        }
};

void matchJob(int employees, vector<vector<int>> applied, vector<vector<int>> managerPref){
    //A 2d vector representing ith employee has applied for applied[i] jobs
    
    int m_pref = managerPref.size();
    vector<vector<double>> scores(m_pref);

    for(int i=0;i<m_pref;i++){
        int n_pref = managerPref[i].size();
        vector<double> temp(n_pref);
        for(int j=0;j<n_pref;j++){
            int km = managerPref[i][j]-1;
            int kn = applied[managerPref[i][j]-1].size();
            for(int k=0;k<kn;k++){

                //find the job preference in applied matrix
                // 1/employeePref * 1/managerPref
                if(applied[km][k]==i+1){
                    temp[j] = (double)23/((k+19)) * 29/((j+17));
                    break;
                }
            }
        }
        scores[i] = temp;
    }

    // vector<vector<pair<int,double>>> employeeScoreList(employees);
    vector<ScoreList> employeeScoreList;

    for(int i=0;i<managerPref.size();i++){
        for(int j=0;j<managerPref[i].size();j++){
            //employee, job, score
            ScoreList scoreobj(managerPref[i][j], i+1, scores[i][j]); 
            employeeScoreList.push_back(scoreobj);
        }
    }

    sort(employeeScoreList.begin(), employeeScoreList.end(), 
        [&](ScoreList a1, ScoreList a2){
            return a1.score>a2.score;
        });
        

   


    // for(auto obj:employeeScoreList){
        
    //     int employee = obj.employee;
    //     int job = obj.job;
    //     double score = obj.score;
    //     cout<<"("<<employee<<","<<job<<","<<score<<")"<<", ";
        
    //     // cout<<endl;
    // }

    unordered_set<int> st;

    for(auto obj :  employeeScoreList){
        if(st.count(obj.employee)==0){
            st.insert(obj.employee);
            int employee = obj.employee;
            int job = obj.job;
            double score = obj.score;
            cout<<"("<<employee<<","<<job<<","<<score<<")"<<", ";
        }
    }

     // for(int i=0;i<employeeScoreList.size();i++){
    //     sort(employeeScoreList[i].begin(), employeeScoreList[i].end(), 
    //         [&](auto a1, auto a2){
    //             return a1.second>a2.second;
    //         });
        
    // }
    // for(auto employee:employeeScoreList){
    //   for(auto job_score:employee){
    //         int job = job_score.first;
    //         double score = job_score.second;
    //         cout<<"("<<job<<"->"<<score<<")"<<", ";
    //   }
    //   cout<<endl;
    // }
}

int main(){

    // jobs = 1 2 3 4 5 6 7 8
    // jobs applied by 5 users A B C D E
    vector<vector<int>> applied = {
        {5, 4, 2, 1, 3},
        {8, 7, 6, 2, 4},
        {3, 2, 1, 7, 6},
        {1, 7, 2, 4, 5},
        {5, 4, 2, 3, 1},
    };
    
    // manager Preference of candidates for the jobs [1...8]
    // managerPref[i] represents a list of candidates in preference order for (i+1) job
    vector<vector<int>> managerPref = {
        {3,1,4,5},
        {4,1,3,5,2},
        {1,5,3},
        {5,1,4,2},
        {4,1,5},
        {2,3},
        {2,4,3},
        {2}
    };
    matchJob(5, applied, managerPref);
    return 0;
}
