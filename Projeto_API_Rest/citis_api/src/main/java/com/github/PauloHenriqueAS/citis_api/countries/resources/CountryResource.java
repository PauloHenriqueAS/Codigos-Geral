package com.github.PauloHenriqueAS.citis_api.countries.resources;

import com.github.PauloHenriqueAS.citis_api.countries.Country;
import com.github.PauloHenriqueAS.citis_api.countries.repository.CountryRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Optional;

@RestController
@RequestMapping("/countries")
//Quando eu fizer um get nessa rota"/countries" ele vai me retornar a lista contendo os paises
public class CountryResource {

    @Autowired
    private CountryRepository repository;


    //Metodo retorna a lista de paises
    @GetMapping
    public Page<Country> countries(Pageable page){
        return repository.findAll(page);
    }

    @GetMapping("/{id}") //Equivale a "/countries/id"
    public ResponseEntity getOne(@PathVariable long id){
        Optional<Country> optional = repository.findById(id);

        //se acharmos o dado pedido respondemos mandando ele se nao mandamos o erro
        if(optional.isPresent()){
            return ResponseEntity.ok().body(optional.get());
        }else{
           return  ResponseEntity.notFound().build();
        }
    }

}
