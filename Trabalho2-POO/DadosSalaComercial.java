package Trabalho2;

import java.util.ArrayList;

public class DadosSalaComercial {
	private ArrayList<SalaComercial> vetSalaComercial = new ArrayList<SalaComercial>();
	
	public void cadastrar(SalaComercial c) {
		this.vetSalaComercial.add(c);
		Persist.salvarBinario("salaComercial.dat", c);//Salvar no arquivo
		System.out.println("Total de salas comerciais inseridos: ");
		System.out.println(this.vetSalaComercial.size());
	}
	
	public void listar(){
		for (SalaComercial objeto: this.vetSalaComercial) {
			objeto.mostarDados();
		}
	}
	
	public SalaComercial buscar(int id) {
		SalaComercial c = null;
		for ( SalaComercial objeto: this.vetSalaComercial) {
			if (objeto.getIdImovel() == id) {
				c = objeto;
				break;
			}
		}
		return c;
	}
	
	//este método usa o método buscar já implementado
	public boolean excluir(int id){
		SalaComercial salaComercialRemove = this.buscar(id);
		
		if(salaComercialRemove != null) {
			this.vetSalaComercial.remove(salaComercialRemove);
			return true;
		}else {
			return false;
		}
	}
}
