// 定義7段顯示器的A腳位
#define seg7_a 2

// 預定義10個7段顯示器的數字位元模式
int seg7_digit[10]{0xfc , 0x60 , 0xda , 0xf2 , 0x66 , 0xb6 , 0xbe , 0xe4 , 0xfe , 0xf6};

// 定義控制4位數字選擇的腳位
int digits[4] = {10, 11, 12, 13};

void setup() {
  // 設定8個7段顯示器的A到H腳位為輸出模式，並初始化為低電位
  for (int i = 0; i < 8; i++) {
    pinMode(seg7_a + i, OUTPUT);
    digitalWrite(seg7_a + i, LOW);
  }
  
  // 設定4個數字選擇腳位為輸出模式，並初始化為高電位
  for (int i = 0; i < 4; i++) {
    pinMode(digits[i], OUTPUT);
    digitalWrite(digits[i], HIGH);
  }
  
  // 將最後一個數字選擇腳位初始化為低電位，以啟用7段顯示器
  digitalWrite(digits[3], LOW);
}

void show(int val){
  int mask0 = B10000000;
  int mask;
  for(int i=0; i<8; i++){
    mask = mask0 >> i;
    if(val&mask) digitalWrite(seg7_a+i, HIGH);
    else digitalWrite(seg7_a+i, LOW);
  }
}

void loop() {
  // 重複顯示10個預定義的數字位元模式
  for (int i = 0; i < 10; i++) {
    show(seg7_digit[i]);
    delay(1000); // 延遲1秒
  }
}


