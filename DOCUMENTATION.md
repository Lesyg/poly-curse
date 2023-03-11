<div align="center">

# Naprogramujte jednoduchou 2D sandbox hru.

</div>

### Hra musí splňovat následující funkcionality

- Implementujte hráče (postava, loď, ...) a jeho stav (energie, životy, brnění, skore, ...)
- Vytvořte (soubojový) model zranění - alespoň dvě příčiny (pád z výšky, soubor s nepřítelem, pobyt v lávě, ...)
- Vytvořte jednoduchý model prostředí (gravitace, přelévání vody (lávy), růst stromů, ...)
- Naimplementujte načítání (konfigurace generátoru) mapy ze souboru a umožněte ukládat aktuální stav hry.

### Kde lze využít polymorfismus? (doporučené)

- Postavy: hráč, zvířata, přítel (obchodník), nepřítel (různé druhy)
- Efekty akcí: pád, úder, kontakt s lávou
- Prostředí: vzduch, voda, hlína, uhlí, kov, láva, žebřík,...
- Uživatelské rozhraní: konzole, ncurses, SDL, OpenGL (různé varianty), ...

<div align="center">

# Upřesnění zadání:

</div>

- Naprogramuji jednoduchou 2D sandboxovou hru, jejíž uživatelské prostředí bude realizováno v terminálu pomocí knihovny ncurses.
Hra bude obsahovat jednu postavu, kterou bude moct hráč ovládat pomocí klávesnice. Bude mít daný počet životů, např 20.
Postava se může pohybovat doleva, doprava, nahoru a dolu. Může vykonávat různé akce. Například těžení bloku, položení vytěženého bloku,
zaútočení na blízkého nepřítele nebo například meditace, která hráči regeneruje životy.
Hra bude počítat hráči skóre jako počet zabitých nepřátel.

- Ve hře se budou vyskytovat dva druhy nepřátel. Bojovník na blízko a bojovník na dálku. Budou mít jednoduchou AI.
Bojovník na blízko se nejdříve pokusí přiblížit k hráči a až bude dostatečně blízko tak zaútočí.
Bojovník na dálku zaútočí na hráče v okamžiku kdy bude v dosahu a když bude hráč moc blízko, tak se bojovník bude snažit od hráče vzdálit.

- Prostředí bude obsahovat jednoduchou krajinu, která se sama vytvoří a nebo může být nahrána ze souboru.
Hra bude moct být uložena do souboru a následně znovu načtena.
V krajině bude například pevné složky například hlína, kámení a tekuté složky voda a láva.

- Hra bude obsahovat jednoduchou fyziku, ve které se pevné složky nepohybují a tekuté složky, pokud mají tu možnost, tak tečou dolů.
Hráč se může pohybovat ve vodě a v lávě, ale pobyt v lávě rapidně ubírá životy a pobyt ve vodě ubírá životy pouze pokud je hráč celý pod vodou po určitou dobu.

### Polymorfismus
- Polymorfismus je použit u třídy Character, která má abstraktní metody attack, move, takeDamageByPlayer, takeDamageByEnemy. Metoda takeDamage jsou přetížené v třídách Player a Ranged a Meele. Metody attack a move jsou přetíženy v
třídách Player, Ranged a Meele.
Dále je polymorfismus použit ve třídě Block s abstraktní metodou stateChange od které bude dědit Static a Liquid a následně Stone, Dirt, Lava a Water a které ji náležitě přetíží.

## Ovládání
- Hráč se pohybuje pomocí klávesnic 'w', 's', 'a', 'd'.
- Hráč zaútočí pomocí ' ' mezerníku.
- Vytěží blok pomocí klávesy 'q'.
- A následně ho položí pomocí 'e'.
- V neposlední řadě může meditovat, aby si zvednul životy pomocí klávesy 'f'.
