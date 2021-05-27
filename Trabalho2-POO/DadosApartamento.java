package Trabalho2;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;

public class DadosApartamento implements Serializable{
	private ArrayList<Apartamento> vetApartamento = new ArrayList<Apartamento>();
	
	public void cadastrar(Apartamento c) {
		this.vetApartamento.add(c);
		Persist.salvarBinario("apartamento.dat", c);//Salvar no arquivo
		System.out.println("Total de apartamentos inseridos: ");
		System.out.println(this.vetApartamento.size());
	}
	
	public void listar(){
		for (Apartamento objeto: this.vetApartamento) {
			objeto.mostarDados();
		}
	}
	
	public Apartamento buscar(int id) {
		Apartamento c = null;
		for ( Apartamento objeto: this.vetApartamento) {
			if (objeto.getIdImovel() == id) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	public boolean excluir(int id){
		Apartamento apartamentoRemove = this.buscar(id);
		
		if(apartamentoRemove != null) {
			this.vetApartamento.remove(apartamentoRemove);
			return true;
		}else {
			return false;
		}
	}
	
}
