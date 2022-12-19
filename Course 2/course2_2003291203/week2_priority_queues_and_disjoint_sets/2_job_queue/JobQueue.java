import java.io.*;
import java.util.StringTokenizer;

public class JobQueue {

    // This is for Worker.
    private int numWorkers;
    private int[] minHeapWorker;
    private long[] nextFreeTime;

    private int[] jobs;

    private int[] assignedWorker;
    private long[] startTime;

    private FastScanner in;
    private PrintWriter out;

    public static void main(String[] args) throws IOException {
        new JobQueue().solve();
    }

    private void readData() throws IOException {
        numWorkers = in.nextInt();
        int m = in.nextInt();
        jobs = new int[m];
        for (int i = 0; i < m; ++i) {
            jobs[i] = in.nextInt();
        }
    }

    private void writeResponse() {
        for (int i = 0; i < jobs.length; ++i) {
            out.println(assignedWorker[i] + " " + startTime[i]);
        }
    }

    private void writeResponse(String fileName) throws IOException {
        FastScanner file = new FastScanner(fileName);
        for (int i = 0; i < jobs.length; i++) {
            assert file.nextInt() == assignedWorker[i] && file.nextLong() == startTime[i];
        }
        out.println("Passed!");
    }

    private void heapify() {
        int k = 0;
        while (k < numWorkers) {
            int left = 2 * k + 1;
            int right = 2 * k + 2;
            int temp_ind = k;
            if (left < numWorkers){
                if (nextFreeTime[minHeapWorker[temp_ind]] > nextFreeTime[minHeapWorker[left]])
                    temp_ind = left;
                else if (
                        nextFreeTime[minHeapWorker[temp_ind]] == nextFreeTime[minHeapWorker[left]] &&
                                minHeapWorker[temp_ind] > minHeapWorker[left]
                )
                    temp_ind = left;
            }
            if (right < numWorkers){
                if (nextFreeTime[minHeapWorker[temp_ind]] > nextFreeTime[minHeapWorker[right]])
                    temp_ind = right;
                else if (
                        nextFreeTime[minHeapWorker[temp_ind]] == nextFreeTime[minHeapWorker[right]] &&
                                minHeapWorker[temp_ind] > minHeapWorker[right]
                )
                    temp_ind = right;
            }
            if (temp_ind != k) {
                int temp = minHeapWorker[temp_ind];
                minHeapWorker[temp_ind] = minHeapWorker[k];
                minHeapWorker[k] = temp;
                k = temp_ind;
            }
            else {
                break;
            }
        }
    }

    private void assignJobs() {
        // TODO: replace this code with a faster algorithm.
        assignedWorker = new int[jobs.length];
        startTime = new long[jobs.length];
        nextFreeTime = new long[numWorkers];
        minHeapWorker = new int[numWorkers];
        for (int i = 0; i < numWorkers; i++) {
            minHeapWorker[i] = i;
        }
        for (int i = 0; i < jobs.length; i++) {
            int chosenWorkerId = minHeapWorker[0];
            assignedWorker[i] = chosenWorkerId;
            startTime[i] = nextFreeTime[chosenWorkerId];
            nextFreeTime[chosenWorkerId] += jobs[i];
            heapify();
        }
    }

    public void solve() throws IOException {
//        String fileName = "D:\\My_project\\Data Structures and Algorithms Specialization\\algorithm_practice\\Course 2\\course2_2003291203\\week2_priority_queues_and_disjoint_sets\\2_job_queue\\tests\\08";
        in = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        readData();
        assignJobs();
        writeResponse();
        out.close();
    }

    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastScanner(String file) throws FileNotFoundException {
            reader = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        }

        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
        }

        public String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}
