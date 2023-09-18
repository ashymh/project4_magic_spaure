#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    int count = 0;

    cout << "마방진의 행 혹은 열의 수를 자연수로 입력해주세요. : ";
    cin >> num;

    int** arr = new int* [num]; // 행 생성

    for (int i = 0; i < num; i++) { // 열 생성
        arr[i] = new int[num];
    }
  
    int x = 0;
    int y = num / 2; //1의 위치 첫번째 행, 가운데 열 고정

    for (int i = 0; i < num * num; i++) {
        count++;

        if (x < 0) {
            x += num; // 첫번째 행보다 초과되면 마지막 행으로 이동
        }

        if (y >= num) {
            y -= num; // 마지막 열보다 초과되면 첫번째 열로 이동
        }
        arr[x][y] = count;

        if (count % num == 0) {
            x++; // 입력한 숫자의 배수일때 행 아래로 한칸 이동
            continue; //continue로 루프 처음으로 돌아감
        }

        x--; //우상향 
        y++;
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

