package zephylix;



//A classe declara que é um visitante. O tipo de retorno dos métodos de visita será Object, a
// classe raiz que usamos para nos referir a um valor Lox em nosso Java código.
// Para satisfazer a interface Visitor, precisamos definir métodos de visita para cada das quatro classes de árvores de
// expressão que nosso analisador produz. Começaremos com o mais simples
public class Interpreter implements Expr.Visitor<Object> {

    @Override
    public Object visitLiteralExpr(Expr.Literal expr) {
        return expr.value;
    }

}
