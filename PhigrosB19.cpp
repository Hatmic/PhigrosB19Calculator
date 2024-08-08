#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

struct Node {
    string name;
    double num;
    double acc;
    double rks;
};

bool cmp(Node x, Node y) {
    return x.rks > y.rks;
}

double calculate_rks(double song_const, double acc) {
    return song_const * pow((acc - 55) / 45.0, 2);
}

int main() {
	freopen("./b19in.txt", "r", stdin);
    freopen("./b19out.txt", "w", stdout);
    
    Node a[200];
    int i = 0;
    double max_song_const_for_acc_100 = 0.0;
    double user_acc = 0.0;
    
    while (true) {
        double acc;
        cin >> a[i].name;
        if (a[i].name == "break") {
        	break;
		}
		
		cin >> a[i].num >> acc;
        a[i].acc = acc;
        a[i].rks = calculate_rks(a[i].num, acc);
        
        if (acc == 100 && a[i].num > max_song_const_for_acc_100) {
            max_song_const_for_acc_100 = a[i].num;
            user_acc = 100;
        }
        
        sort(a, a + i + 1, cmp);
        
        i++;
    }
    
    cout << "B0: " << fixed << setprecision(3) << max_song_const_for_acc_100 << endl;
    
    double user_rks = 0.0;
    
    for (int j = 0; j <= i; j++) {
        cout << "B" << j+1 << " " << a[j].name << " " << fixed << setprecision(3) << a[j].rks << " " << a[j].acc << "%" << endl;
        
        if (j < 19) {
        	user_rks += a[j].rks;
        	user_acc += a[j].acc;
		}
		
		if (j == 18) {
			cout << "------" << endl;
		}
    }
    
    user_rks += max_song_const_for_acc_100;
    cout << "rks: " << fixed << setprecision(3) << user_rks / 20.0 << endl;
    cout << "acc: " << fixed << setprecision(2) << user_acc / 20.0 << endl;
    
    cout << endl << "https://space.bilibili.com/1974288318" << endl;
    
    return 0;
}

