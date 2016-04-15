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
public enum Operation {
    NULL,
    ADDITION,
    SOUSTRACTION,
    MULTIPLICATION,
    DIVISION;
    
    public String toString(){
        if(this == ADDITION)
            return "+";
        if(this == SOUSTRACTION)
            return "-";
        if(this == MULTIPLICATION)
            return "*";
        if(this == DIVISION)
            return "/";
        return null;
    }
    
}
