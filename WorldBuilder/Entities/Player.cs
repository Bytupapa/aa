using System.Collections.Generic;

namespace WorldBuilder.Entities
{
    public class Player : Character
    {
        public List<Resource> Inventory { get; } = new List<Resource>();
        public Player(string name) : base(name) {}

        public void Collect(Resource resource)
        {
            Inventory.Add(resource);
        }
    }
}
