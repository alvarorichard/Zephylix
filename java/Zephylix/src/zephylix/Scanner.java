package zephylix;

import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;
import java.util.Map;

import static zephylix.TokenType.*;

public class Scanner {
    private final String source;
    private final List<Token> tokens = new ArrayList<>();

    Scanner(String source) {
        this.source = source;
    }
}
