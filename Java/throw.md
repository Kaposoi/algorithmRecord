# throw

throw用于在方法体内抛出异常。

throw new ScoreExpection();用这个语句之前要先在方法指定throws ScoreExpection();

throw new ScoreExpection("string") 会抛出自己给的异常。



public class ScoreExpection() extends Expection {

​	public ScoreExpection()

​	public ScoreExpection(String message) {

​		super(message);

​	}

}