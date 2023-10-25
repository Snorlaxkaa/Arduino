int i , sum;
void setup() {
  // put your setup code here, to run once:
  sum=0;
  i=1;
  Serial.begin(9600);// Serial.begin(包率)又名波特率,设置为 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  if(i<=100){// 如果 i 小于等于 100，执行下面的代码
    sum=sum+1;
    i=i+1;
    Serial.print("i");// 在串行监视器中输出字符 "i"
    Serial.print("i=");// 在串行监视器中输出字符 "i="
    Serial.print("\n");// 在串行监视器中输出换行符
    Serial.print("sum");// 在串行监视器中输出字符 "sum"
    Serial.print("sum=");// 在串行监视器中输出字符 "sum="
    Serial.print("\n");// 在串行监视器中输出换行符
    //Serial.print可以放(字串,變數,字元(friting))
  }
}
