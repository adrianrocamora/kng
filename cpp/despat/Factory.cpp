Option* CreateOption(PlayerOptions optionType) {
    Option* pOption = nullptr;
    switch(optinType) {
        case PlayerOptions::GoNorth:
            pOption = new MoveOption(
                Room::JoiningDirections::North,
                PlayerOptions::GoNorth, "Go North");
            break;
        case PlayerOptions::GoSouth:
            pOption = new MoveOption(
                Room::JoiningDirections::South,
                PlayerOptions::GoSouth, "Go South");
            break;
        case PlayerOptions::GoEast:
            pOption = new MoveOption(
                Room::JoiningDirections::East,
                PlayerOptions::GoEast, "Go East");
            break;
        case PlayerOptions::GoWest:
            pOption = new MoveOption(
                Room::JoiningDirections::West,
                PlayerOptions::GoWest, "Go West");
            break;
        case PlayerOptions::OpenChest:
            pOption = new OpenChestOption("Open Chest");
            break;
        case PlayerOptions::AttackEnemy:
            pOption = new AttackEnemyOption();
            break;
        case PlayerOptions::Quit:
            pOption = new QuitOption("Quit");
            break;
        case PlayerOptions::None:
            break;
        default:
            break;
    }
    return Option;
}
