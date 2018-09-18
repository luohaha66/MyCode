package in.thread;

public class Cons extends Thread {

	private Mythread mythread;

	public Cons(Mythread mythread) {
		super();
		this.mythread = mythread;
	}

	public Cons() {
		// TODO Auto-generated constructor stub
	}

	public Cons(Runnable target) {
		super(target);
		// TODO Auto-generated constructor stub
	}

	public Cons(String name) {
		super(name);
		// TODO Auto-generated constructor stub
	}

	public Cons(ThreadGroup group, Runnable target) {
		super(group, target);
		// TODO Auto-generated constructor stub
	}

	public Cons(ThreadGroup group, String name) {
		super(group, name);
		// TODO Auto-generated constructor stub
	}

	public Cons(Runnable target, String name) {
		super(target, name);
		// TODO Auto-generated constructor stub
	}

	public Cons(ThreadGroup group, Runnable target, String name) {
		super(group, target, name);
		// TODO Auto-generated constructor stub
	}

	public Cons(ThreadGroup group, Runnable target, String name, long stackSize) {
		super(group, target, name, stackSize);
		// TODO Auto-generated constructor stub
	}

	public Cons(ThreadGroup group, Runnable target, String name, long stackSize, boolean inheritThreadLocals) {
		super(group, target, name, stackSize, inheritThreadLocals);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		synchronized (mythread) {
			super.run();
			while (true) {
				if (mythread.isEmpty()) {
					try {
						Thread.sleep(100);
						mythread.wait();
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				else {
					System.out.println("2222");
					mythread.setEmpty(true);
					mythread.notify();
				}
			}
		}
	}

}
