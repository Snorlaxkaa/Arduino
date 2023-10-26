#define V1 11 // 巨集，將V1設定為11，這樣在程式中出現V1會自動被替換成11
const int V2=22; // 常數，將V2設定為22，這個值之後不能更改
int M; // 宣告一個整數變數M，用來儲存後面計算的結果

void setup() { 
  // 這個函式在程式開始時只會執行一次
  Serial.begin(9600); // 初始化串列通訊，設定傳輸速率為9600
  const int V3=33; // 局部常數，只在這個setup函式內有效，設定為33
  
  M=V2+V3; // 計算M的值為V2+V3，也就是22+33=55
  // V2=100; // 這行會出錯，因為V2是常數，不能更改其值
  
  Serial.println("HELLO"); // 透過串列通訊輸出"HELLO"，只會執行一次
  Serial.println(M); // 輸出M的值，也就是55
}

void loop() {
  // 這個函式會不停地重複執行
  // Serial.println("HELLO"); // 如果取消註解，會不停地輸出"HELLO"
}
