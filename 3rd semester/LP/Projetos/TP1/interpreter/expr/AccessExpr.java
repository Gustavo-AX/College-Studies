package interpreter.expr;

import java.util.List;
import java.util.Map;
import interpreter.InterpreterException;
import interpreter.value.*;

public class AccessExpr extends SetExpr {

    private SetExpr base;
    private Expr index;

    public AccessExpr(int line, SetExpr base, Expr index) {
        super(line);
        this.base = base;
        this.index = index;
    }

    @Override
    public Value<?> expr() {
        if (base.expr() instanceof ListValue) {
            int i = (int) NumberValue.convert(index.expr());
            ListValue lv = (ListValue) base.expr();
            List<Value<?>> value = lv.value();
            if (i < value.size())
                return value.get(i);
            else {
                return null;
            }

        } else if (base.expr() instanceof ObjectValue) {

            TextValue tv = new TextValue(TextValue.convert(index.expr()));
            ObjectValue ov = (ObjectValue) base.expr();
            Map<TextValue, Value<?>> value = ov.value();
            if (value.containsKey(tv))
                return value.get(tv);
            else
                return null;
        } else {
            throw new InterpreterException(super.getLine());
        }
    }

    @Override
    public void setValue(Value<?> value) {
        if (base.expr() instanceof ListValue) {
            int i = (int) NumberValue.convert(index.expr());
            ListValue lv = (ListValue) base.expr();
            List<Value<?>> var = lv.value();
            if (i < var.size()) {
                var.set(i, value);
                ListValue temp = new ListValue(var);
                base.setValue(temp);
            } else {
                // até o indice, adciono null, que será convertido para undefined
                for (int w = var.size(); w < i; w++) {
                    var.add(w, null);
                }

                // coloco em i o valor especificado
                var.add(i, value);
            }

        } else if (base.expr() instanceof ObjectValue) {
            TextValue tv = new TextValue(TextValue.convert(index.expr()));
            ObjectValue ov = (ObjectValue) base.expr();
            Map<TextValue, Value<?>> var = ov.value();
            var.replace(tv, value);
        } else {
            throw new InterpreterException(super.getLine());
        }
    }

}