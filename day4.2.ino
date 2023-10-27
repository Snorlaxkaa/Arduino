// 定義LED和按鈕分別連接到的腳位
#define LedPin 13
#define BtnPin 2

// 声明计数器变量，用于存储按钮按下次数
int cnt;

// 声明标志变量，用于确保按钮每次被按下只计数一次
int flag;

// 声明去抖动（debounce）相关的变量
int lastDebounceTime; // 记录上一次触发去抖动的时间
int debounceDelay;    // 设置去抖动的延迟时间
int btnState;         // 存储当前按钮状态
int lastBtnState = HIGH; // 记录上一次的按钮状态，初始化为HIGH（未按下）

void setup() {
  // 初始化串口通信，设置波特率（baud rate）为9600
  Serial.begin(9600);

  // 设置按键和LED的脚位模式
  pinMode(BtnPin, INPUT_PULLUP); // 按键设置为输入模式并启用内部上拉电阻
  pinMode(LedPin, OUTPUT); // LED设置为输出模式

  // 初始化LED为关闭状态
  digitalWrite(LedPin, LOW);

  // 初始化计数器和标志变量
  cnt = 0;
  flag = 0;

  // 初始化去抖动相关变量
  lastDebounceTime = 0;
  debounceDelay = 50; // 去抖动延迟设为50毫秒
}

void loop() {
  // 读取按键的当前状态
  int reading = digitalRead(BtnPin);

  // 如果按键状态与上一次不同，则重设去抖动时间
  if (reading != lastBtnState) {
    lastDebounceTime = millis();
  }

  // 如果经过了足够长的时间（去抖动时间），则认为按键状态改变
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != btnState) {
      btnState = reading;
    }
  }

  // 更新存储的上一次按键状态
  lastBtnState = reading;

  // 如果当前按键状态为LOW（即被按下）并且标志变量为0
  if (btnState == LOW && flag == 0) {
    // 点亮LED
    digitalWrite(LedPin, HIGH);

    // 增加计数器的值
    cnt++;

    // 设置标志变量为1，表示已计数
    flag = 1;

    // 通过串口输出当前计数器的值
    Serial.print("Counter = ");
    Serial.println(cnt);
  } else {
    // 关闭LED
    digitalWrite(LedPin, LOW);

    // 重置标志变量为0
    flag = 0;
  }
}
