package in.thread;

public class Pro extends Thread {

	private Mythread mythread;

	public Pro() {
		// TODO Auto-generated constructor stub
	}

	public Pro(Runnable target) {
		super(target);
		// TODO Auto-generated constructor stub
	}

	public Pro(Mythread mythread) {
		super();
		this.mythread = mythread;
	}

	public Pro(String name) {
		super(name);
		// TODO Auto-generated constructor stub
	}

	public Pro(ThreadGroup group, Runnable target) {
		super(group, target);
		// TODO Auto-generated constructor stub
	}

	public Pro(ThreadGroup group, String name) {
		super(group, name);
		// TODO Auto-generated constructor stub
	}

	public Pro(Runnable target, String name) {
		super(target, name);
		// TODO Auto-generated constructor stub
	}

	public Pro(ThreadGroup group, Runnable target, String name) {
		super(group, target, name);
		// TODO Auto-generated constructor stub
	}

	public Pro(ThreadGroup group, Runnable target, String name, long stackSize) {
		super(group, target, name, stackSize);
		// TODO Auto-generated constructor stub
	}

	public Pro(ThreadGroup group, Runnable target, String name, long stackSize, boolean inheritThreadLocals) {
		super(group, target, name, stackSize, inheritThreadLocals);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		synchronized (mythread) {
			super.run();
			while (true) {
				if (!mythread.isEmpty()) {
					try {
						Thread.sleep(100);
						mythread.wait();
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				else {
					System.out.println("11111");
					mythread.setEmpty(false);
					mythread.notify();
				}
			}
		}
	}

}
