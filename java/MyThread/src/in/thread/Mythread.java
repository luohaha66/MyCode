package in.thread;

public class Mythread extends Thread {

	private boolean isEmpty = true;

	public boolean isEmpty() {
		return this.isEmpty;
	}

	public void setEmpty(boolean isEmpty) {
		this.isEmpty = isEmpty;
	}

	public Mythread() {
		// TODO Auto-generated constructor stub
	}

	public Mythread(Runnable target) {
		super(target);
		// TODO Auto-generated constructor stub
	}

	public Mythread(String name) {
		super(name);
		// TODO Auto-generated constructor stub
	}

	public Mythread(ThreadGroup group, Runnable target) {
		super(group, target);
		// TODO Auto-generated constructor stub
	}

	public Mythread(ThreadGroup group, String name) {
		super(group, name);
		// TODO Auto-generated constructor stub
	}

	public Mythread(Runnable target, String name) {
		super(target, name);
		// TODO Auto-generated constructor stub
	}

	public Mythread(ThreadGroup group, Runnable target, String name) {
		super(group, target, name);
		// TODO Auto-generated constructor stub
	}

	public Mythread(ThreadGroup group, Runnable target, String name, long stackSize) {
		super(group, target, name, stackSize);
		// TODO Auto-generated constructor stub
	}

	public Mythread(ThreadGroup group, Runnable target, String name, long stackSize, boolean inheritThreadLocals) {
		super(group, target, name, stackSize, inheritThreadLocals);
		// TODO Auto-generated constructor stub
	}

	@Override
	public synchronized void run() {
		// TODO Auto-generated method stub
		super.run();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Mythread mythread = new Mythread();
		Cons cons = new Cons(mythread);
		Pro pro = new Pro(mythread);
		cons.start();
		pro.start();
	}

}
