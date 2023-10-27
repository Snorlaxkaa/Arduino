// 定義按鈕連接的腳位，編號為2
#define ButtonPin 2

// 宣告一個整數變數cnt，用於儲存按鈕被按下的次數
int cnt;

// 宣告一個整數變數flag，用於確保按鈕每次被按下後只會計數一次
int flag;

void setup() {
  // 初始化串口通信，設定傳輸速率為9600 bits per second（每秒9600位）
  Serial.begin(9600);

  // 將按鈕連接的腳位（ButtonPin）設定為輸入模式，並啟用內部上拉電阻
  pinMode(ButtonPin, INPUT_PULLUP);

  // 初始化計數器cnt為0
  cnt = 0;

  // 初始化標誌變數flag為0
  flag = 0;

  // 在串口監視器上輸出初始的計數器值
  Serial.print("計數值=");
  Serial.println(cnt);
}

void loop() {
  // 主要程式碼，會不斷地重複執行

  // 如果按鈕狀態為HIGH（即未被按下），則將標誌變數設回0
  if (digitalRead(ButtonPin) == HIGH)
    flag = 0;

  // 如果按鈕狀態為LOW（即被按下）並且標誌變數為0（即還未計數這一次的按壓）
  if (digitalRead(ButtonPin) == LOW && flag == 0) {
    // 將計數器加1
    cnt++;

    // 在串口監視器上輸出新的計數值
    Serial.print("計數值=");
    Serial.println(cnt);

    // 將標誌變數設為1，表示這一次的按壓已經被計數過
    flag = 1;
  }
}
