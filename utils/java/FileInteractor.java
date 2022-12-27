package utils.java;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URI;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class FileInteractor {

    private File file;
    private List<String> rawContents;

    public FileInteractor(String fileName) {
        this.file = new File(fileName);
    }
    
    public FileInteractor(File parent, String fileName) {
        this.file = new File(parent, fileName);
    }

    public FileInteractor(String parent, String fileName) {
        this.file = new File(parent, fileName);
    }

    
    public FileInteractor(URI uri) {
        this.file = new File(uri);
    }

    public File getFile() {
        return file;
    }

    public List<String> getrawContents() {
        return rawContents;
    }

    public FileInteractor readLines() {
        this.rawContents = new ArrayList<>();
        try {
            Scanner myReader = new Scanner(this.file);
            while (myReader.hasNextLine()) {
              String data = myReader.nextLine();
              rawContents.add(data);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("Can't not interact with file " + this.file.getName());
            e.printStackTrace();
        }
        return this;
    }

    public List<String> toWords() {
        List<String> words = new ArrayList<>();
        for (String line: this.rawContents) {
            for(String w: line.split("\\s"))
                words.add(w);
        }
        return words;
    }


    public void writeLines(List<String> rawContents) {
        try {
            if (this.file.createNewFile()) {
              System.out.println("File created: " + this.file.getName());
            }
        } catch (IOException e) {
            System.out.println("Can't create " + this.file.getName());
            e.printStackTrace();
        }

        try {
            FileWriter myWriter = new FileWriter(this.file.getName());
            for (String line: rawContents) {
                myWriter.write(line + "\n");
            }
            myWriter.close();
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("Can't write to this file " + this.file.getName());
            e.printStackTrace();
        }
        this.rawContents = rawContents;
    }

    public void deleteFile() { 
        if (this.file.delete()) { 
            System.out.println("Deleted the file: " + this.file.getName());
        } else {
            System.out.println("Failed to delete the file.");
        } 
    }

    
    // public static void main(String[] args) {
    //     String fileName = "D:\\My_project\\Data Structures and Algorithms Specialization\\algorithm_practice\\Course 2\\course2_2003291203\\week3_hash_tables\\2_hash_chains\\tests\\06";
    //     FileInteractor file = new FileInteractor(fileName);
    //     System.out.println(file.readLines().toWords());
        
    // }


    
}

class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastScanner(String fileName) throws FileNotFoundException {
            reader = new BufferedReader(new InputStreamReader(new FileInputStream(fileName)));
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
    }
