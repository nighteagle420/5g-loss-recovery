
#include "Classes.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// struct node {
//   int mod_index;
//   double code_rate;
//   double spec_eff;
// };

// typedef struct node r;

User embb_table[] = {
    User(2, 193, 0.3770), User(2, 308, 0.6016), User(2, 449, 0.8770),
    User(2, 602, 1.1758), User(4, 378, 1.4766), User(4, 434, 1.6953),
    User(4, 490, 1.9141), User(4, 553, 2.1602), User(4, 616, 2.4063),
    User(4, 658, 2.5704), User(6, 466, 2.7305), User(6, 517, 3.0293),
    User(6, 567, 3.3223), User(6, 616, 3.6094), User(6, 719, 4.2129),
    User(6, 772, 4.5234), User(6, 822, 4.8164), User(6, 873, 5.1152),
    User(8, 682.5, 5.3320), User(8, 711, 5.5547), User(8, 754, 5.8906),
    User(8, 797, 6.2266), User(8, 841, 6.5703), User(8, 885, 6.9141),
    User(8, 916.5, 7.1602), User(8, 948, 7.4063)};

// r embb_table[27] = {
//     {2, 193, 0.3770},   {2, 308, 0.6016}, {2, 449, 0.8770},   {2,
//     602, 1.1758}, {4, 378, 1.4766},   {4, 434, 1.6953}, {4, 490, 1.9141}, {4,
//     553, 2.1602}, {4, 616, 2.4063},   {4, 658, 2.5704}, {6, 466, 2.7305}, {6,
//     517, 3.0293}, {6, 567, 3.3223},   {6, 616, 3.6094}, {6, 719, 4.2129}, {6,
//     772, 4.5234}, {6, 822, 4.8164},   {6, 873, 5.1152}, {8, 682.5, 5.3320},
//     {8, 711, 5.5547}, {8, 754, 5.8906},   {8, 797, 6.2266}, {8, 841, 6.5703},
//     {8, 885, 6.9141}, {8, 916.5, 7.1602}, {8, 948, 7.4063}};

User urllc_table[] = {
    User(2, 40, 0.0781), User(2, 50, 0.0977), User(2, 64, 0.1250),
    User(2, 78, 0.1523), User(2, 99, 0.1934), User(2, 120, 0.2344),
    User(2, 157, 0.3066), User(2, 193, 0.3770), User(2, 251, 0.4902),
    User(2, 308, 0.6016), User(2, 379, 0.7402), User(2, 449, 0.8770),
    User(2, 526, 1.0273), User(2, 602, 1.1758), User(4, 340, 1.3281),
    User(4, 378, 1.4766), User(4, 434, 1.6953), User(4, 490, 1.9141),
    User(4, 553, 2.1602), User(4, 616, 2.4063), User(6, 438, 2.5664),
    User(6, 466, 2.7305), User(6, 517, 3.0293), User(6, 567, 3.3223),
    User(6, 616, 3.6094), User(6, 666, 3.9023), User(6, 719, 4.2129),
    User(6, 772, 4.5234)};

// r urllc_table[28] = {
//     {2, 40, 0.0781},  {2, 50, 0.0977},  {2, 64, 0.1250},  {2, 78, 0.1523},
//     {2, 99, 0.1934},  {2, 120, 0.2344}, {2, 157, 0.3066}, {2, 193, 0.3770},
//     {2, 251, 0.4902}, {2, 308, 0.6016}, {2, 379, 0.7402}, {2, 449, 0.8770},
//     {2, 526, 1.0273}, {2, 602, 1.1758}, {4, 340, 1.3281}, {4, 378, 1.4766},
//     {4, 434, 1.6953}, {4, 490, 1.9141}, {4, 553, 2.1602}, {4, 616, 2.4063},
//     {6, 438, 2.5664}, {6, 466, 2.7305}, {6, 517, 3.0293}, {6, 567, 3.3223},
//     {6, 616, 3.6094}, {6, 666, 3.9023}, {6, 719, 4.2129}, {6, 772, 4.5234}};

int main()
{
    srand((unsigned)time(0));
    int i;
    // input
    int no_of_embb_users = 10; // 10

    User embb_user[no_of_embb_users];

    for (int count = 0; count < no_of_embb_users;
         count++) // storing random no_of_embb_users values
    {
        // i = count;
        i = (rand() % 26);
        embb_user[count] = {embb_table[i].mod_index, embb_table[i].code_rate,
                            embb_table[i].spec_eff};
    }

    vector<int> rb_req_embb(no_of_embb_users, 0);
    double total_rb_count = 0;
    for (int count = 0; count < no_of_embb_users; count++) // storing rb req of embb users
    {
        rb_req_embb[count] = Utility::getRequiredResourceBlocks(
            embb_user[count].mod_index, embb_user[count].code_rate);
        // 4 * ceil((32 * 1024) / ((embb_user[count].mod_index) *
        //                                            (embb_user[count].code_rate) *
        //                                            (12) * (14) * (0.6)));
        total_rb_count += rb_req_embb[count];
    }

    vector<double> channel_quality_embb(no_of_embb_users);

    double power_embb[no_of_embb_users];

    // double total_power_budget;
    for (int count = 0; count < no_of_embb_users; count++) // storing power of embb users
    {
        power_embb[count] = Utility::getPower(rb_req_embb[count]);
        // 39.81 / rb_req_embb[count];
        // total_power_budget += power_embb[count];
    }

    double SNR_embb[no_of_embb_users];
    int bandwidth = 20;

    for (int count = 0; count < no_of_embb_users; count++) // storing SNR of embb users
    {
        SNR_embb[count] = Utility::getSNR(bandwidth, embb_user[count].spec_eff);
        // (int)pow(2, embb_user[count].spec_eff / bandwidth) - 1;
    }

    for (int count = 0; count < no_of_embb_users; count++) // storing channel quality of embb users
    {
        channel_quality_embb[count] =
            Utility::getChannelQuality(SNR_embb[count], power_embb[count]);
    }

    vector<pair<double, double>> channel_rb_embb;

    for (int count = 0; count < no_of_embb_users; count++)
    {
        channel_rb_embb.push_back({channel_quality_embb[count], rb_req_embb[count]});
    }

    sort(channel_rb_embb.rbegin(), channel_rb_embb.rend());

    //------------------------------------------------------------------------------------------------------
    // map<double, int> embb_map;
    // //   double channel_quality_embb;
    // map<double, int> urllc_map;
    // //   double channel_quality_urllc;

    // for (int count = 0; count < no_of_embb_users; count++)
    // {
    //     double channelQuality =
    //         Utility::getChannelQuality(SNR_embb[count], power_embb[count]);
    //     embb_map[channelQuality] = rb_req_embb[count];
    // }

    // unordered_map<int, int> curr, prev;

    // sort the urllc users according to channel quality(highest first)
    // can store them in map/priority_queue

    vector<pair<double, double>> channel_rb_embb_copy = channel_rb_embb;

    double percent = 0.8; // take input of sic percentage from user
    // vector<int> effective_rb(no_of_embb_users);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    unordered_set<int> prev_idx, curr_idx;
    vector<vector<double>> effective_rb(8, vector<double>(no_of_embb_users, 0));

    vector<double> average_rate_embb(no_of_embb_users);
    vector<double> data_rate_embb(no_of_embb_users);
    vector<vector<double>> rolling_rate(10, vector<double>(no_of_embb_users, 0));

    for (int count = 0; count < no_of_embb_users; count++) // storing data rate of embb users
    {
        data_rate_embb[count] = Utility::getDataRate(embb_user[count].spec_eff, bandwidth);
    }



    ///////////////////////
    //////////////////////
    /////////////////////
    ////////////////////////////////
    ////////////////////////////
    /////////////////////////////
    int extra_rb = 0;

    for (int timeframe = 0; timeframe < 10; timeframe++)
    {
        int loss_sum[no_of_embb_users] = {0};
   
        prev_idx.clear();
        curr_idx.clear();

        cout << "----------------------------------------------------\n";
        cout << "TIME FRAME : " << timeframe << endl;
        cout << "----------------------\n";

        int no_of_urllc_users = 1 + (rand() % 5); // 5
        cout << "URLLC Users are : " << no_of_urllc_users << endl;

        cout << endl;
        // for (int i = 0; i < channel_rb_embb.size(); i++)
        // {
        //     cout << i + 1 << " ";
        // }
        cout << endl
             << "---------------------" << endl;

        User urllc_user[no_of_urllc_users];
        for (int count = 0; count < no_of_urllc_users;
             count++) // storing random no_of_urllc_users values
        {
            i = (rand() % 28);
            urllc_user[count] = {urllc_table[i].mod_index, urllc_table[i].code_rate,
                                 urllc_table[i].spec_eff};
        }

        vector<int> rb_req_urllc(no_of_urllc_users, 0);
        for (int count = 0; count < no_of_urllc_users; count++) // storing rb req of urllc users//////////////////////////////////////////////////////
        {
            rb_req_urllc[count] = Utility::getRequiredResourceBlocks(
                urllc_user[count].mod_index, urllc_user[count].code_rate);
        }

        vector<double> channel_quality_urllc(no_of_urllc_users);
        double power_urllc[no_of_urllc_users];
        for (int count = 0; count < no_of_urllc_users; count++) // storing power of urllc users
        {
            power_urllc[count] = Utility::getPower(rb_req_urllc[count]);
            // 39.81 / rb_req_embb[count];
            //  total_power_budget += power_embb[count];
        }

        double SNR_urllc[no_of_urllc_users];

        for (int count = 0; count < no_of_urllc_users; count++) // storing SNR of urllc users
        {
            SNR_urllc[count] = Utility::getSNR(bandwidth, urllc_user[count].spec_eff);
            // (int)pow(2, embb_user[count].spec_eff / bandwidth) - 1;
        }

        for (int count = 0; count < no_of_urllc_users; count++) // storing channel quality of urllc users
        {
            channel_quality_urllc[count] =
                Utility::getChannelQuality(SNR_urllc[count], power_urllc[count]);
        }

        vector<pair<double, double>> channel_rb_urllc;

        for (int count = 0; count < no_of_urllc_users; count++)
        {
            channel_rb_urllc.push_back({channel_quality_urllc[count], rb_req_urllc[count]});
        }

        sort(channel_rb_urllc.rbegin(), channel_rb_urllc.rend());
        vector<double> data_rate_embb_copy = data_rate_embb;
        vector<pair<double, double>> channel_rb_urllc_copy;

        //-----------------------------------------------------------------------------------------------------

        for (int minislots = 0; minislots < 8; minislots++)
        {
            channel_rb_urllc_copy = channel_rb_urllc;
            channel_rb_embb_copy = channel_rb_embb;

            for (auto &it : channel_rb_embb_copy)
            {
                it.second += extra_rb;
            }

            vector<pair<double, double>> channel_rb_embb_standard = channel_rb_embb_copy;

            for (auto it : channel_rb_embb_copy)
            {
                cout << it.second << " ";
            }
            cout << "\t";

            for (int count_urllc = 0, count_embb = 0, backptr = no_of_embb_users - 1; count_urllc < no_of_urllc_users && count_embb < no_of_embb_users && backptr >= count_embb;)
            {
                auto &h_urllc = channel_rb_urllc_copy[count_urllc].first;
                auto &h_embb = channel_rb_embb_copy[count_embb].first;
                auto &rb_urllc = channel_rb_urllc_copy[count_urllc].second;
                auto &rb_embb = channel_rb_embb_copy[count_embb].second;
                // rb_embb+=extra_rb;

                if (h_urllc < h_embb)
                {
                    // sic
                    if (rb_embb >= rb_urllc)
                    {
                        effective_rb[minislots][count_embb] += rb_urllc * (1 - percent);
                        rb_embb -= rb_urllc;
                        rb_urllc = 0;
                        count_urllc++;

                        continue;
                    }
                    else
                    {
                        effective_rb[minislots][count_embb] += rb_embb * (1 - percent);
                        rb_urllc -= rb_embb;
                        rb_embb = 0;

                        count_embb++;
                        continue;
                    }
                }
                else
                {
                    while (backptr >= count_embb)
                    {
                        auto &backptr_rb_embb = channel_rb_embb_copy[backptr].second;
                        if (prev_idx.find(backptr) == prev_idx.end())
                        {
                            if (backptr_rb_embb > rb_urllc)
                            {
                                // cout<<"else part 1"<<endl;
                                backptr_rb_embb -= rb_urllc;
                                rb_urllc = 0;
                                count_urllc++;
                                //
                            }
                            else
                            {
                                // cout<<"else part2"<<endl;;
                                rb_urllc -= backptr_rb_embb;
                                backptr_rb_embb = 0;
                                // discrimination
                                // store index of this
                                curr_idx.insert(backptr);
                                backptr--;
                            }
                        }
                        else
                        {
                            backptr--;
                        }
                    }
                }
            }
            for (int i = 0; i < no_of_embb_users; i++)
            {
                effective_rb[minislots][i] += channel_rb_embb_copy[i].second + (loss_sum[i]/8);
                data_rate_embb_copy[i] = data_rate_embb[i] *(effective_rb[minislots][i]/channel_rb_embb[i].second);
                // if (effective_rb[minislots][i] == 0)
                // {
                //     curr_idx.insert(i);
                // }
            }

            for (int i = 0; i < no_of_embb_users; i++)
            {
                for (int minislot = 1; minislot <= 8; minislot++)
                {
                    rolling_rate[timeframe][i] = ((1 - (1.0 / minislot)) * rolling_rate[timeframe][i]) + (1.0 / minislot) * data_rate_embb_copy[i];
                }
            }

            prev_idx = curr_idx;
            curr_idx.clear();

            for (int i = 0; i < channel_rb_embb.size(); i++)
            {
                cout << channel_rb_embb_standard[i].second - channel_rb_embb_copy[i].second << " ";
                loss_sum[i] += abs(floor(channel_rb_embb_standard[i].second - channel_rb_embb_copy[i].second));
            }
            cout << endl;

        } // end of minislot

      
        
        cout << "Extra rb is " << extra_rb << endl;
        cout << endl
             << "---------------------" << endl;
    } // end of time frame

  

    // cout<<"Total loss "<<(total_rb_count * 8) - loss_sum<<endl;

    // printing rate 2d vector
    for (int i = 0; i < effective_rb.size(); i++)
    {
        for (int j = 0; j < effective_rb[0].size(); j++)
        {
            cout << effective_rb[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < no_of_embb_users; i++)
    {
        for (int timeframe = 0; timeframe < 10; timeframe++)
            average_rate_embb[i] += rolling_rate[timeframe][i];
            
            average_rate_embb[i]/=10;
    }
    cout << "                ****************************                " << endl;
    cout << "                     ^^^^^^^^^^^^^^^^                       " << endl;
    cout << " --------------  LOSS RECOVERY OF EMBB USERS  ---------------" << endl;
    cout << "                     ^^^^^^^^^^^^^^^^                       " << endl;
    cout << "                ****************************                " << endl;

    // for (int i = 0; i < no_of_embb_users; i++)
    // {
    //     cout << average_rate_embb[i] << " ";
    // }
    for (int i = 0; i < no_of_embb_users; i++)
    {
        cout << 100-((data_rate_embb[i] / average_rate_embb[i]) * 100) << " ";
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // for 8 mini-slots
    /*for (int time = 0; time < 8; time++)
    {
      for (int count_embb = no_of_embb_users - 1, count_urllc = no_of_urllc_users - 1; count_urllc >= 0;)
      {
        auto h_urllc = channel_rb_urllc_copy[count_urllc].first;
        auto h_embb = channel_rb_embb_copy[count_embb].first;
        auto rb_urllc = channel_rb_urllc_copy[count_urllc].second;
        auto rb_embb = channel_rb_embb_copy[count_embb].second;
        if (h_urllc < h_embb)
        {
          // sic
          if (rb_embb != 0)
          {
            if (rb_embb >= rb_urllc)
            {
              count_urllc--;
              rb_embb -= rb_urllc;
              effective_rb[count_embb] += rb_urllc * (1 - percent);//////////////////////////////////////////////////////////////////////////////////////
              rb_urllc = 0;
            }
            else
            {
              rb_urllc -= rb_embb;
              rb_embb = 0;
              count_embb--;
            }
          }
          else
          {
            count_embb--;
            continue;
          }
          // embb_rate_copy[it->first] = percent * embb_rate_copy[it->first];
        }
        else
        {
          // puncturing
          for (auto i : channel_rb_embb_copy)
          {
            if (prev.find(i.first) == prev.end())
            {
              // puncturing
              if (rb_urllc >= i.second)
              {
                rb_urllc -= i.second;
                curr[i.first]++;
                continue;
              }
              else
              {
                i.second -= rb_urllc;
              }
            }
          }
          prev = curr; // embb_users stored whose rb allocated = 0, for priority in next round
          curr.clear();
        }
        // when i encounter i, I skip for puncturing.
      }
      if (time == 0)
      {
      }
      else
      {
        // for (int count = 0; count < no_of_embb_users; count++)
        // {
        //     rolling_average[count] = (prev_rb[count] * effective_rb[count] + channel_rb_embb_copy[count_embb].second * effective_rb) / rb_req_embb[count];
        // }
        // calculating total loss
        int loss_sum = 0;
        for (int count = 0; count < no_of_embb_users; count++)
        {
          loss_sum += (channel_rb_embb[count].second - channel_rb_embb_copy[count].second);
        }
        cout << loss_sum << endl;
      }
    }
    */
    // rolling weighted average=(n(p) * rate(prev)+n(curr) * rate(current))/n(reqd)
    return 0;
}
