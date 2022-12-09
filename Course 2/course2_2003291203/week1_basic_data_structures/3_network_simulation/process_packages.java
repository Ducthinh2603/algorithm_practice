import javax.swing.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;
import java.util.stream.Collectors;

class Request {
    public Request(int arrival_time, int process_time) {
        this.arrival_time = arrival_time;
        this.process_time = process_time;
    }

    public int arrival_time;
    public int process_time;
}

class Response {
    public Response(boolean dropped, int start_time) {
        this.dropped = dropped;
        this.start_time = start_time;
    }

    public boolean dropped;
    public int start_time;
}

class Buffer {
    public Buffer(int size) {
        this.size_ = size;
        this.timeSeries = new int[LIMIT];
    }

    public Response Process(Request request) {
        // write your code here
        boolean dropped = false;
        int start_time = -1;
        if (request.arrival_time > clock || (request.arrival_time < LIMIT &&
                timeSeries[request.arrival_time] < this.size_)) {

            dropped = true;
            start_time = Math.max(request.arrival_time, clock);
            this.clock = start_time + request.process_time;
            for (int i = request.arrival_time; i < this.clock && i < LIMIT; i++) {
                timeSeries[i]++;
            }
            if (this.clock < LIMIT && this.clock > 0)
                timeSeries[this.clock] = timeSeries[this.clock - 1] - 1;
        }

        return new Response(dropped, start_time);
    }

    private int size_;
    private int[] timeSeries;
    private int clock = 0;
    final private int LIMIT = 1000000;
}

class process_packages {
    private static ArrayList<Request> ReadQueries(Scanner scanner) throws IOException {
        int requests_count = scanner.nextInt();
        ArrayList<Request> requests = new ArrayList<Request>();
        for (int i = 0; i < requests_count; ++i) {
            int arrival_time = scanner.nextInt();
            int process_time = scanner.nextInt();
            requests.add(new Request(arrival_time, process_time));
        }
        return requests;
    }

    private static ArrayList<Response> ProcessRequests(ArrayList<Request> requests, Buffer buffer) {
        ArrayList<Response> responses = new ArrayList<Response>();
        for (int i = 0; i < requests.size(); ++i) {
            responses.add(buffer.Process(requests.get(i)));
        }
        return responses;
    }

    private static void PrintResponses(ArrayList<Response> responses) {
        for (int i = 0; i < responses.size(); ++i) {
            Response response = responses.get(i);
            if (response.dropped) {
                System.out.println(-1);
            } else {
                System.out.println(response.start_time);
            }
        }
    }

    public static void check(String test, List<Integer> myRs, List<Integer> rs) {
        boolean allMatch = true;
        for (int i = 0; i < myRs.size(); i++) {
            if (!Objects.equals(myRs.get(i), rs.get(i))) {
                allMatch = false;
                break;
            }
        }
        if (allMatch) {
            System.out.println(test + ": TRUE");
        } else {
            System.out.println(test + ": WRONG");
        }
    }

    public static void mainProcess() throws IOException {
        Scanner scanner = new Scanner(System.in);
        process(scanner, true);
    }

    public static void mainProcess(int testNum) {
        Scanner scanner;
        String test = testNum < 10 ? "0" : "";
        test += testNum;
        String filename = "D:\\My_project\\Data Structures and Algorithms Specialization\\algorithm_practice\\Course 2\\course2_2003291203\\week1_basic_data_structures\\3_network_simulation\\tests\\" + test;
        try {
            File testCase = new File(filename);
            scanner = new Scanner(testCase);
            List<Integer> myRs = process(scanner);
            scanner.close();

            File testAnswer = new File(filename + ".a");
            scanner = new Scanner(testAnswer);
            List<Integer> answer = new ArrayList<>();
            while (scanner.hasNextInt()) {
                answer.add(scanner.nextInt());
            }
            scanner.close();
            check(test, myRs, answer);
        } catch (FileNotFoundException e) {
            System.out.println("File " + filename + " not found");

            e.printStackTrace();
        } catch (IOException e) {
            System.out.println("Can't open file.");
        }

    }

    public static void process(Scanner scanner, boolean printRes) throws IOException {
        int buffer_max_size = scanner.nextInt();
        Buffer buffer = new Buffer(buffer_max_size);

        ArrayList<Request> requests = ReadQueries(scanner);
        ArrayList<Response> responses = ProcessRequests(requests, buffer);
        if (printRes)
            PrintResponses(responses);
    }

    public static List<Integer> process(Scanner scanner) throws IOException {

        int buffer_max_size = scanner.nextInt();
        Buffer buffer = new Buffer(buffer_max_size);

        ArrayList<Request> requests = ReadQueries(scanner);
        ArrayList<Response> responses = ProcessRequests(requests, buffer);
        return responses.stream().map(x -> x.start_time).collect(Collectors.toList());
    }

    public static void main(String[] args) throws IOException {
//        for (int i = 1; i <= 22; i++)
//            mainProcess(i);
        mainProcess();
    }
}
