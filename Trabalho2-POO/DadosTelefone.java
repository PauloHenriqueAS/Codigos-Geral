package Trabalho2;

import java.util.ArrayList;

public class DadosTelefone {
private ArrayList<Telefone> vetTelefone = new ArrayList<Telefone>();
	
	public void cadastrar(Telefone c) {
		this.vetTelefone.add(c);
		Persist.salvarBinario("telefones.dat", c);//Salvar no arquivo
		System.out.println("Total de telefones inseridos: ");
		System.out.println(this.vetTelefone.size());
	}
	
	public void listar(){
		for (Telefone objeto: this.vetTelefone) {
			objeto.mostarDados();
		}
	}
	
	public Telefone buscar(String telContato) {
		Telefone c = null;
		for ( Telefone objeto: this.vetTelefone) {
			if (objeto.getTelContato().equals(telContato)) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(String telContato){
		Telefone telefoneRemove = this.buscar(telContato);
		
		if(telefoneRemove != null) {
			this.vetTelefone.remove(telefoneRemove);
			return true;
		}else {
			return false;
		}
	}
}
