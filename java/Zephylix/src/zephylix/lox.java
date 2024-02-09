package zephylix;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.nio.charset.Charset;
import java.util.*;

import static zephylix.TokenType.*;

public class lox {
    static boolean hadError = false;

    public static void main(String[] args) {
        if (args.length > 1) {
            System.out.println("Usage: lox [script]");
            System.exit(64);
        } else if (args.length == 1) {
            runFile(args[0]);
        } else {
            runPrompt();
        }
    }

    private static void runFile(String path) throw IOException{
        byte[] bytes = Files.readAllBytes(Paths.get(path));
        run(new String(bytes, Charset.defaultCharset()));
        if (hadError) System.exit(65);

    }
    private static void runPrompt() throws IOException {
        InputStreamReader input = new InputStreamReader(System.in);
        BufferedReader reader = new BufferedReader(input);
        for (;;) {
            System.out.print("> ");
            String line = reader.readLine();
            if (line == null) break;
            run(line);
            hadError = false;
        }
    }


    private static void run (String source) {
        Scanner scanner = new Scanner(source);
        List<Token> tokens = scanner.scanTokens();

        // por agora, so imprime os tokens
        for (Token token : tokens) {
            System.out.println(token);
        }
    }

    static void error(int line, String message) {
        report(line, "", message);
    }
    private static void report(int line, String where, String message) {
        System.err.println(
            "[line " + line + "] Error" + where + ": " + message);
        hadError = true;
    }








}
