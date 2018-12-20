import java.io.*;

public class SimpleHello {
	public static void sayHalloWelt() {
		System.out.println("Hallo Welt");
	}
	public void sayWorld() {
		System.out.println("World");
	}
	public static void main(String[] args) {
		System.out.print("Hello ");
		SimpleHello shel = new SimpleHello();
		shel.sayWorld();
		sayHalloWelt();
	}
}
