int hashFunc26(char Since[], int len) {
    int id = 0;
    for (int i = 0; i < len; i++) {
        id = id * 26 + (Since[i] - 'A');
    }
    return id;
}

int hashFunc52(char Since[], int len) {
    int id = 0;
    for (int i = 0; i < len; i++) {
        if (Since[i] >= 'A' && Since[i] <= 'Z')
            id = id * 52 + (Since[i] - 'A');
        else if (Since[i] >= 'a' && Since[i] <= 'z')
            id = id * 52 + (Since[i] - 'a') + 26;
    }
    return id;
}
//
// Created by 陈至宇 on 2022/2/23.
//

