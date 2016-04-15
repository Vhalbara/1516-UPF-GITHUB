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
public interface CalculatriceOperationListener {
    void onNumberPressed(Double number);
    void onOperationPressed(Operation op);
    void onEnterPressed();
    void onResetAsked();
}
