/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package V2;



/**
 *
 * @author thomas
 */
public class CalculatricaApp implements CalculatriceOperationListener{
    
    private Double nb1 = -1.00, nb2 =0.00;
    private Operation operation = Operation.NULL;
    private final Calculatrice ui;

    
    public CalculatricaApp() {
        this.ui = new Calculatrice();
        this.ui.addCalOperationListener(this);
    }
    
    public void display() {
        this.ui.setVisible(true);
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        CalculatricaApp calculatricaApp = new CalculatricaApp();
        calculatricaApp.display();
    }

    @Override
    public void onNumberPressed(Double number) {
        System.out.println("onNumberPressed");
        this.nb2 = number + (this.nb2*10);
        ui.setText(Double.toString(this.nb2));
    }

    @Override
    public void onOperationPressed(Operation op) {
        System.out.println("onOperationPressed");
        if(this.operation == Operation.NULL){
            this.nb1 = this.nb2;
            this.operation = op;
            ui.setText(Double.toString(this.nb1) + " " + op);
            this.nb2 = 0.00;
        }else{
            Double rep = 0.00;
            if(this.operation == Operation.NULL){
                rep = this.nb2;
            }
            if(this.operation == Operation.ADDITION){
                rep = this.nb1+this.nb2;
            }
            if(this.operation == Operation.SOUSTRACTION){
                rep = this.nb1-this.nb2;
            }
            if(this.operation == Operation.MULTIPLICATION){
                rep = this.nb1*this.nb2;
            }
            if(this.operation == Operation.DIVISION){
                if(this.nb2 == 0.00)
                    ui.setText("Div. par Zéro impossible");
                else{
                    rep = this.nb1/this.nb2;
                }
            }
            this.nb1 = rep; this.nb2 = 0.00;
            ui.setText(Double.toString(rep));
        }
    }

    @Override
    public void onEnterPressed() {
        System.out.println("onEnterPressed");
        Double rep = 0.00;
        if(this.operation == Operation.NULL){
            rep = this.nb2;
            ui.setText("= " + Double.toString(this.nb2));
        }
        if(this.operation == Operation.ADDITION){
            rep = this.nb1+this.nb2;
            ui.setText(Double.toString(rep) + " = " + Double.toString(this.nb1) + " + " + Double.toString(this.nb2));
        }
        if(this.operation == Operation.SOUSTRACTION){
            rep = this.nb1-this.nb2;
            ui.setText(Double.toString(rep) + " = " + Double.toString(this.nb1) + " - " + Double.toString(this.nb2));
        }
        if(this.operation == Operation.MULTIPLICATION){
            rep = this.nb1*this.nb2;
            ui.setText(Double.toString(rep) + " = " + Double.toString(this.nb1) + " * " + Double.toString(this.nb2));
        }
        if(this.operation == Operation.DIVISION){
            if(this.nb2 == 0.00)
                ui.setText("Div. par Zéro impossible");
            else{
                rep = this.nb1/this.nb2;
                ui.setText(Double.toString(rep) + " = " + Double.toString(this.nb1) + " / " + Double.toString(this.nb2));
            }
        }
        this.nb1 = -1.00; this.nb2 = rep; this.operation= Operation.NULL;
    }
    
    @Override
    public void onResetAsked(){
        System.out.println("onResetAsked");
        this.nb1 = -1.00; 
        this.nb2 = 0.00; 
        this.operation = Operation.NULL;
        ui.setText("0");
    }
    
}
